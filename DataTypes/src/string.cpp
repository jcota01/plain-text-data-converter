//
// Created by 01jac on 23/12/2023.
//

#include "data_types.h"

String::String(std::string nodeName) : DataNode(std::move(nodeName)) {
    value = nullptr;
}

String::String(const std::string &val, std::string nodeName) : DataNode(std::move(nodeName)) {
    value = std::make_unique<std::string>(val);
}

std::string String::toString(){
    std::string str = nameToString();
    str += (value) ? *value : "";

    return str;
}

void String::set(const std::string& val){
    value = std::make_unique<std::string>(val);
}