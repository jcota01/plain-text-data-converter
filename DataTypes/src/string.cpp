//
// Created by 01jac on 23/12/2023.
//

#include <utility>

#include "data_types.h"

String::String(std::string nodeName) : DataNode(std::move(nodeName)) {
    value = nullptr;
}

std::unique_ptr<String> String::create(std::string nodeName){
    return std::unique_ptr<String>(new String(std::move(nodeName)));
}

std::string String::toString(){
    std::string str = nameToString();
    str += (value) ? *value : "";

    return str;
}

void String::set(const std::string& val){
    value = std::make_unique<std::string>(val);
}
