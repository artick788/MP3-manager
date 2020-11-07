#include <iostream>
#include "EngineCore/Andromeda.h"

#include "AndromedaUtils.h"
#include "Window.h"
#include "Camera.h"
#include "Model.h"

static float fov = 45.0f;
static bool firstMouse = true;
static float yaw = -90.0f;
static float pitch = 0.0f;
static float lastX = 0.0f;
static float lastY = 0.0f;
static glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);

void scrollCallback(GLFWwindow* window, double xOffset, double yOffset){
    fov -= (float)yOffset;
    if (fov < 1.0f){
        fov = 1.0f;
    }
    else if (fov > 45.0f){
        fov = 45.0f;
    }
}

void mouseCallback(GLFWwindow * window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f; // change this value to your liking
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (pitch > 89.0f){
        pitch = 89.0f;
    }
    if (pitch < -89.0f){
        pitch = -89.0f;
    }

    glm::vec3 front1;
    front1.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front1.y = sin(glm::radians(pitch));
    front1.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = front1;
}

void processInput(Andromeda::Window* window, Andromeda::Camera* &cam){
    cam->setCameraPos(front);
    if (window->getKey(GLFW_KEY_W) == GLFW_PRESS){
        cam->moveForward(0.1f);
    }
    if (window->getKey(GLFW_KEY_A) == GLFW_PRESS){
        cam->moveLeft(0.1f);
    }
    if (window->getKey(GLFW_KEY_D) == GLFW_PRESS){
        cam->moveRight(0.1f);
    }
    if (window->getKey(GLFW_KEY_S) == GLFW_PRESS){
        cam->moveBack(0.1f);
    }
    if (window->getKey(GLFW_KEY_SPACE) == GLFW_PRESS){
        cam->moveUp(0.1f);
    }
    if (window->getKey(GLFW_KEY_C) == GLFW_PRESS){
        cam->moveDown(0.1f);
    }
    if (window->getKey(GLFW_KEY_ESCAPE) == GLFW_PRESS){
        window->close();
    }
    if (window->getMouseInput(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
        double mouseX = 0;
        double mouseY = 0;
        window->getMousePosition(mouseX, mouseY);
        std::cout << "position x: " << mouseX << ", position y:" << mouseY << std::endl;
    }
}

int main(){
    std::string shaderTextVFS = "./Resources/Shaders/Text-vfs.glsl";
    std::string shaderTextFFS = "./Resources/Shaders/Text-ffs.glsl";
    std::string shaderVFS = "./Resources/Shaders/Texture-vfs.glsl";
    std::string shaderFFS = "./Resources/Shaders/Texture-ffs.glsl";
    std::string modelPath = "./Resources/Models/Cube.ini";
    std::string texturePath = "./Resources/Textures/helo_fish.jpg";
    std::string font = "./Resources/Fonts/arial.ttf";

    try {
        Andromeda::andromedaInit();
        Andromeda::Window window(800, 600, "Andromeda");
        window.enableVerticalSync(true);
        window.setMouseInputMode(GLFW_CURSOR_DISABLED);
        window.setWindowIcon(texturePath);
        window.setScrollCallback(scrollCallback);
        window.setMousePosCallback(mouseCallback);
        andromedaCore::AdromedaCoreInit();
        std::cout << "Max number of vertex attributes: " << andromedaCore::getMaxVertexAttribs() << std::endl;
        std::cout << "Max size of UBO: " << andromedaCore::getMaxUBOsize() << std::endl;
        std::cout << "running openGL version: " << andromedaCore::getOpenGLversion() << std::endl;

        auto* camera = new Andromeda::Camera();
        auto* shaderModel = new andromedaCore::Shader(shaderVFS, shaderFFS);
        auto* cube = new Andromeda::Model(modelPath);
        auto* cubeRenderer = new andromedaCore::Renderer(cube->getVertices(), cube->getIndices(), cube->getLayout(), shaderModel);
        auto* texture = new andromedaCore::Texture2D(texturePath);
        texture->setParameter(GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        texture->setParameter(GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

        auto* shaderText = new andromedaCore::Shader(shaderTextVFS, shaderTextFFS);
        auto* textRenderer = new andromedaCore::TextRenderer(font, shaderText);
        shaderText->bind();
        glm::mat4 test = window.getOrthogonalMatrix();
        shaderText->setUniformMatrix4f("u_Projection", &window.getOrthogonalMatrix()[0][0]);
        shaderText->setUniform3f("u_TextColor", 0.2f, 1.0f, 1.0f);

        std::vector<float> uniforms = {1.0f, 2.0f, 3.0f};

        std::string text = "YEET\nyos";
        andromedaCore::ZBuffer zBuffer;
        andromedaCore::CullfaceBuffer cfb(GL_BACK);
        while (!window.windowShouldClose()){
            window.clear();
            zBuffer.clear();
            window.setColor(0.8f, 0.3f, 0.5f);
            processInput(&window, camera);

            texture->bind(0);
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0.0f, -0.0f, -3.0f));
            shaderModel->bind();
            shaderModel->setUniformMatrix4f("u_Model", &model[0][0]);
            shaderModel->setUniformMatrix4f("u_Projection", &window.getPerspectiveMatrix(fov, 0.1f, 100.0f)[0][0]);
            shaderModel->setUniformMatrix4f("u_View", &camera->getViewMatrix()[0][0]);
            cubeRenderer->drawElements(cube->getDrawMode());

            textRenderer->draw(text, 400.0f, 400.0f, 1.0f);


            window.swapBuffers();

            Andromeda::andromedaPollEvents();

        }
        Andromeda::andromedaTerminate();

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    } catch (...) {
        std::cerr << "ERROR::UNDEFINED" << std::endl;
    }
    std::cout << "FINISHED" << std::endl;
    return 0;
}
