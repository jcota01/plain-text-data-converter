//
// Created by 01jac on 23/12/2023.
//

#include <utility>

#include "data_types.h"

Object::Object(DataNode* obj, std::string nodeName) : DataNode(std::move(nodeName)){
    values.push_back(obj);
}

Object::Object(std::string nodeName) : DataNode(std::move(nodeName)){}

void Object::addChild(DataNode* obj){
    values.push_back(obj);
}

[[nodiscard]] std::string Object::toString() {
    std::string str = nameToString();

    for (auto & elem: values){
        str += elem->toString();
        str += " ; ";
    }

    return str;
}