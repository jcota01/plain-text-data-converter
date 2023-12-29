//
// Created by 01jac on 29/12/2023.
//

#include "data_types.h"

std::unique_ptr<Bool> Bool::create(std::string&& nodeName, bool val){
    return std::unique_ptr<Bool>(new Bool(std::move(nodeName), val));
}

[[nodiscard]]std::string Bool::toString(){
    // Gets "NAME : "
    std::string str = nameToString();
    // Adds bool value to string
    str += value ? "true" : "false";

    return str;
}

void Bool::set(bool val){
    value = val;
}

Bool::Bool(std::string&& nodeName, bool val) : DataNode(std::move(nodeName), DataType::BOOL), value(val){}