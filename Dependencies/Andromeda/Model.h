#ifndef ANDROMEDA_MODEL_H
#define ANDROMEDA_MODEL_H

#include "AndromedaLib.h"
#include "EngineCore/VertexArray.h"


namespace Andromeda{
    class Model{
    private:
        ini::Configuration m_Config;

        unsigned int m_NrOfVertices;
        unsigned int m_NrOfFaces;

        andromedaCore::VertexBufferLayout* m_Layout;

        std::vector<float> m_Vertices;
        std::vector<unsigned int> m_Indices;
        unsigned int m_DrawMode;

        void parse();
        void addVertices();
        void addFaces();

        std::string parseVerticesName(unsigned int a);
        std::string parseFaceName(unsigned int a);

    public:
        Model(const std::string& fileName);

        static std::vector<unsigned int> triangulate(const std::vector<unsigned int>& indices);

        const std::vector<float> &getVertices() const;

        const std::vector<unsigned int> &getIndices() const;

        unsigned int getDrawMode() const;

        andromedaCore::VertexBufferLayout *getLayout() const;
    };
}
#endif //ANDROMEDA_MODEL_H
