//
// Created by arthu on 20/08/2020.
//

#ifndef INI_PARSER_INI_PARSER_H
#define INI_PARSER_INI_PARSER_H

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>

namespace ini{
    class Value{
    private:
        std::string m_Name;
        std::string m_Value;

        void removeBullshit(std::string& in);

    public:
       Value(std::string& name, std::string& value);

       std::string getName();

       std::string returnStringOrDie();

       int returnIntOrDie();

       unsigned int returnUnsignedIntOrDie();

       float returnFloatOrDie();

       bool returnBoolOrDie();

       double returnDoubleOrDie();

       std::vector<int> returnIntTupleOrDie();

       std::vector<unsigned int> returnUnsignedIntTupleOrDie();

       std::vector<double> returnDoubleTupleOrDie();

       std::vector<float> returnFloatTupleOrDie();

    };

    class Node{
    private:
        std::string m_Name;
        std::vector<Value> m_Values;
    public:
        Node(const std::string name);

        void addValue(Value val);

        std::string getName();

        Value operator[](const std::string& valName);
    };

    class Configuration{
    private:
        std::vector<Node> m_Nodes;
    public:
        Configuration(const std::string& fileName);

        Configuration();

        Node operator[](const std::string& object);

    };
}


#endif //INI_PARSER_INI_PARSER_H
