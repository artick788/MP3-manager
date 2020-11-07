//
// Created by arthu on 20/08/2020.
//

#include "ini_parser.h"

ini::Value::Value(std::string &name, std::string &value): m_Name(name), m_Value(value) {

}

std::string ini::Value::getName() {
    return m_Name;
}

std::string ini::Value::returnStringOrDie() {
    return m_Value;
}

int ini::Value::returnIntOrDie() {
    return std::stoi(m_Value);
}

unsigned int ini::Value::returnUnsignedIntOrDie() {
    return (unsigned int) std::stoi(m_Value);
}

float ini::Value::returnFloatOrDie() {
    return std::stof(m_Value);
}

double ini::Value::returnDoubleOrDie() {
    return std::stod(m_Value);
}

bool ini::Value::returnBoolOrDie() {
    bool retVal;
    std::istringstream(m_Value) >> retVal;
    return retVal;
}

void ini::Value::removeBullshit(std::string &in) {
    std::string::iterator endPos = std::remove(in.begin(), in.end(), ' ');
    in.erase(endPos, in.end());
    std::string::iterator lBracketPos = std::remove(in.begin(), in.end(), '{');
    in.erase(lBracketPos, in.end());
    std::string::iterator rBracketPos = std::remove(in.begin(), in.end(), '}');
    in.erase(rBracketPos, in.end());
}

std::vector<int> ini::Value::returnIntTupleOrDie() {
    if (m_Value.find('{') != std::string::npos and m_Value.find('}') != std::string::npos){
        std::vector<int> retVal;
        removeBullshit(m_Value);
        std::stringstream ss(m_Value);
        while(ss.good()){
            std::string substr;
            std::getline(ss, substr, ',');
            if (!substr.empty()){
                retVal.push_back(std::stoi(substr));
            }
        }
        return retVal;
    }
    else{
        std::string error = "Invalid tuple layout at: " + m_Name;
        throw std::runtime_error(error);
    }
}

std::vector<unsigned int> ini::Value::returnUnsignedIntTupleOrDie() {
    if (m_Value.find('{') != std::string::npos and m_Value.find('}') != std::string::npos){
        std::vector<unsigned int> retVal;
        removeBullshit(m_Value);
        std::stringstream ss(m_Value);
        while(ss.good()){
            std::string substr;
            std::getline(ss, substr, ',');
            if (!substr.empty()){
                retVal.push_back((unsigned int) std::stoi(substr));
            }
        }
        return retVal;
    }
    else{
        std::string error = "Invalid tuple layout at: " + m_Name;
        throw std::runtime_error(error);
    }
}

std::vector<double> ini::Value::returnDoubleTupleOrDie() {
    if (m_Value.find('{') != std::string::npos and m_Value.find('}') != std::string::npos){
        std::vector<double> retVal;
        removeBullshit(m_Value);
        std::stringstream ss(m_Value);
        while(ss.good()){
            std::string substr;
            std::getline(ss, substr, ',');
            if (!substr.empty()){
                retVal.push_back(std::stod(substr));
            }
        }
        return retVal;
    }
    else{
        std::string error = "Invalid tuple layout at: " + m_Name;
        throw std::runtime_error(error);
    }
}

std::vector<float> ini::Value::returnFloatTupleOrDie() {
    if (m_Value.find('{') != std::string::npos and m_Value.find('}') != std::string::npos){
        std::vector<float> retVal;
        removeBullshit(m_Value);
        std::stringstream ss(m_Value);
        while(ss.good()){
            std::string substr;
            std::getline(ss, substr, ',');
            if (!substr.empty()){
                retVal.push_back(std::stof(substr));
            }
        }
        return retVal;
    }
    else{
        std::string error = "Invalid tuple layout at: " + m_Name;
        throw std::runtime_error(error);
    }
}

ini::Node::Node(const std::string name) {
    m_Name = name;
}

void ini::Node::addValue(ini::Value val) {
    m_Values.push_back(val);

}

std::string ini::Node::getName() {
    return m_Name;
}

ini::Value ini::Node::operator[](const std::string &valName) {
    for (auto& value : m_Values){
        if (value.getName() == valName){
            return value;
        }
    }
    std::string error = "Invalid entry in section: " + valName;
    throw std::runtime_error(error);
}

ini::Configuration::Configuration(const std::string &fileName) {
    std::fstream file(fileName);
    std::string line;
    Node current("EXTRANODENONFUNCT");
    while(std::getline(file, line)){
        if (line.empty()){
            continue;
        }
        if (line.find('#') != std::string::npos){
            continue;
        }
        if (line.find('[')!= std::string::npos and line.find(']') != std::string::npos){
            m_Nodes.push_back(current);
            std::string nodeName;
            for (int a = 0; a < line.size(); a++){
                if (line[a] == '[' or line[a] == ']'){
                    continue;
                }
                else{
                    nodeName += line[a];
                }
            }
            Node newNode(nodeName);
            current = newNode;
        }
        else{
            std::string valName;
            std::string value;
            std::string::iterator endPos = std::remove(line.begin(), line.end(), ' ');
            line.erase(endPos, line.end());
            int index = line.find('=');
            for (int a = 0; a < line.size(); a++){
                if (a < index){
                    valName += line[a];
                }
                else if (a > index){
                    value += line[a];
                }
            }
            Value newVal(valName, value);
            current.addValue(newVal);
        }
    }
    m_Nodes.push_back(current);

}

ini::Node ini::Configuration::operator[](const std::string& object) {
    for (auto& node : m_Nodes){
        if (node.getName() == object){
            return node;
        }
    }
    std::string error = "Invalid entry in section: " + object;
    throw std::runtime_error(error);
}

ini::Configuration::Configuration() {

}
