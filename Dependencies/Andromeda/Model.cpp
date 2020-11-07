#include "Model.h"

Andromeda::Model::Model(const std::string &fileName) {
    ini::Configuration temp(fileName);
    m_Config = temp;
    parse();
}

std::vector<unsigned int> Andromeda::Model::triangulate(const std::vector<unsigned int> &indices) {
    unsigned int size = (indices.size() - 2) * 3;
    std::vector<unsigned int> retVal;
    retVal.reserve(size);
    for (unsigned int a = 1; a < indices.size() - 1; a++){
        retVal.push_back(indices[0]);
        retVal.push_back(indices[a]);
        retVal.push_back(indices[a + 1]);
    }
    return retVal;
}

std::string Andromeda::Model::parseVerticesName(unsigned int a) {
    return "V" + std::to_string(a);
}

std::string Andromeda::Model::parseFaceName(unsigned int a) {
    return "F" + std::to_string(a);
}

void Andromeda::Model::parse() {
    m_NrOfVertices = m_Config["GENERAL"]["NR_OF_VERTICES"].returnUnsignedIntOrDie();
    m_NrOfFaces = m_Config["GENERAL"]["NR_OF_FACES"].returnUnsignedIntOrDie();
    std::vector<unsigned int> attribs = m_Config["GENERAL"]["LAYOUT"].returnUnsignedIntTupleOrDie();
    unsigned int vertexSize= m_Config["GENERAL"]["VERTEX_SIZE"].returnUnsignedIntOrDie();
    std::string drawMethod = m_Config["GENERAL"]["DRAWMODE"].returnStringOrDie();
    m_Layout = new andromedaCore::VertexBufferLayout(vertexSize, attribs);
    if (drawMethod == "TRIANGLES"){
        m_DrawMode = GL_TRIANGLES;
    }
    else if (drawMethod == "LINES"){
        m_DrawMode = GL_LINES;
    }
    else if (drawMethod == "QUADS"){
        m_DrawMode = GL_QUADS;
    }
    else{
        throw std::runtime_error("ANDROMEDA::MODEL::PARSE::UNDEFINED_DRAW_METHOD");
    }
    addFaces();
    addVertices();
}

void Andromeda::Model::addVertices() {
    m_Vertices.reserve(m_NrOfVertices);
    for (unsigned int a = 0; a < m_NrOfVertices; a++){
        std::vector<float> vertice = m_Config["VERTICES"][parseVerticesName(a)].returnFloatTupleOrDie();
        m_Vertices.insert(m_Vertices.end(), vertice.begin(), vertice.end());
    }

}

void Andromeda::Model::addFaces() {
    m_Indices.reserve(m_NrOfFaces);
    for (unsigned int a = 0; a < m_NrOfFaces; a++){
        std::vector<unsigned int> indices = m_Config["FACES"][parseFaceName(a)].returnUnsignedIntTupleOrDie();
        m_Indices.insert(m_Indices.end(), indices.begin(), indices.end());
    }
}

const std::vector<float> &Andromeda::Model::getVertices() const {
    return m_Vertices;
}

const std::vector<unsigned int> &Andromeda::Model::getIndices() const {
    return m_Indices;
}

unsigned int Andromeda::Model::getDrawMode() const {
    return m_DrawMode;
}

andromedaCore::VertexBufferLayout *Andromeda::Model::getLayout() const {
    return m_Layout;
}
