//
// Created by 01jac on 29/12/2023.
//

#include "data_types.h"

std::unique_ptr<Null> Null::create(std::string&& nodeName){
    return std::unique_ptr<Null>(new Null(std::move(nodeName)));
}

[[nodiscard]]std::string Null::toString(){
    // Gets "NAME : "
    std::string str = nameToString();
    str += "null";

    return str;
}

Null::Null(std::string&& nodeName) : DataNode(std::move(nodeName), DataType::NULL_TYPE){}