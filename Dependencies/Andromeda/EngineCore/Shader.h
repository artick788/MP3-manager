//
// Created by arthu on 05/10/2020.
//

#ifndef ADROMEDA_SHADER_H
#define ADROMEDA_SHADER_H

#include "AndromedaCoreLib.h"

namespace andromedaCore{
    class Shader {
    private:
        enum class ShaderType{
            NONE = 0,
            VERTEX = 1,
            FRAGMENT = 2,
            GEOMETRY = 3
        };

        unsigned int m_ShaderProgram;

        std::string readFromFile(const std::string& fileName);

        unsigned int buildAndCompileShader(const char* shaderSource, ShaderType type);

        void link(unsigned int& vertexShader, unsigned int& fragmentShader);

        unsigned int getUniformLocation(const std::string& name);

    public:
        Shader(const std::string &vertexShaderFile, const std::string &fragmentShaderFile);

        Shader(const char* &vertexShaderSource, const char* &fragmentShaderSource);

        ~Shader();

        void bind();

        void unbind();

        void setUniform1ui(const std::string& name, unsigned int ui1);

        void setUniform2ui(const std::string& name, unsigned int ui1, unsigned int ui2);

        void setUniform3ui(const std::string& name, unsigned int ui1, unsigned int ui2, unsigned int ui3);

        void setUniform4ui(const std::string& name, unsigned int ui1, unsigned int ui2, unsigned int ui3, unsigned int ui4);

        void setUniform1i(const std::string& name, unsigned int i1);

        void setUniform2i(const std::string& name, unsigned int i1, unsigned int i2);

        void setUniform3i(const std::string& name, unsigned int i1, unsigned int i2, unsigned int i3);

        void setUniform4i(const std::string& name, unsigned int i1, unsigned int i2, unsigned int i3, unsigned int i4);

        void setUniform1f(const std::string& name, float f1);

        void setUniform2f(const std::string& name, float f1, float f2);

        void setUniform3f(const std::string& name, float f1, float f2, float f3);

        void setUniform4f(const std::string& name, float f1, float f2, float f3, float f4);

        void setUniformMatrix2f(const std::string& name, const float* value);

        void setUniformMatrix3f(const std::string& name, const float* value);

        void setUniformMatrix4f(const std::string& name, const float* value);

        void setUniform1d(const std::string& name, double d1);

        void setUniform2d(const std::string& name, double d1, double d2);

        void setUniform3d(const std::string& name, double d1, double d2, double d3);

        void setUniform4d(const std::string& name, double d1, float d2, double d3, double d4);

        void setUniformMatrix2d(const std::string& name, const double* value);

        void setUniformMatrix3d(const std::string& name, const double* value);

        void setUniformMatrix4d(const std::string& name, const double* value);

    };
}


#endif //ADROMEDA_SHADER_H
