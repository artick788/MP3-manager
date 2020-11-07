#ifndef ANDROMEDA_RENDERER_H
#define ANDROMEDA_RENDERER_H

#include "AndromedaCoreLib.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Text.h"

namespace andromedaCore{
    class Renderer{
    private:
        unsigned int m_VerticesCount;

    protected:
        IndexBuffer* m_IBO;
        VertexBuffer* m_VBO;
        VertexArray* m_VAO;
        Shader* m_Shader;

        Renderer();

    public:
        Renderer(const std::vector<float>& data, VertexBufferLayout* layout, Shader* shader);

        Renderer(const std::vector<float>& data, const std::vector<unsigned int>& indices, VertexBufferLayout* layout, Shader* shader);

        void drawArrays(unsigned int drawMode);

        void drawElements(unsigned int drawMode);

    };

    class DynamicRenderer: public Renderer{
    private:
        unsigned int m_SizeVBO;

    public:
        DynamicRenderer(unsigned int vboSize, VertexBufferLayout* layout, Shader* shader);

        DynamicRenderer(unsigned int vboSize, unsigned int iboSize, VertexBufferLayout* layout, Shader* shader);

        void drawArrays(unsigned int drawMode, unsigned int offset, const std::vector<float>& data);

        void drawElements(unsigned int drawMode, unsigned int vboOffset, const std::vector<float>& vertices,
                          unsigned int iboOffset, const std::vector<unsigned int>& indices);



    };

    class TextRenderer: public Renderer{
    private:
        Text* m_TextID;

    public:
        TextRenderer(const std::string& font, Shader* shader);

        void draw(const std::string& text, float xPos, float yPos, float scale);
    };
}

#endif //ANDROMEDA_RENDERER_H
