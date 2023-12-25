//
// Created by 01jac on 23/12/2023.
//

#include "data_types.h"

Object::Object(std::string&& nodeName) : DataNode(std::move(nodeName), DataType::OBJECT){}

std::unique_ptr<Object> Object::create(std::string&& nodeName){
    return std::unique_ptr<Object>(new Object(std::move(nodeName)));
}

void Object::addChild(std::unique_ptr<DataNode>&& node){
    values.push_back(std::move(node));
}

[[nodiscard]] std::string Object::toString() {
    std::string str = nameToString();

    for (auto & elem: values){
        str += elem->toString();
        str += " ; ";
    }

    return str;
}