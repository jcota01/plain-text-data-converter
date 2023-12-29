//
// Created by 01jac on 23/12/2023.
//

#include "data_types.h"

String::String(std::string&& nodeName) : DataNode(std::move(nodeName), DataType::STRING) {
    // By default, the value is null, it must be set using set()
    value = nullptr;
}

std::unique_ptr<String> String::create(std::string&& nodeName){
    return std::unique_ptr<String>(new String(std::move(nodeName)));
}

std::string String::toString(){
    // Get "NAME : "
    std::string str = nameToString();
    // If there is a value stored, then add that, otherwise (if value == nullptr) add nothing
    str += (value) ? *value : "";

    return str;
}

void String::set(std::string&& val){
    value = std::make_unique<std::string>(val);
}
