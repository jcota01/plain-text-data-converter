//
// Created by 01jac on 23/12/2023.
//

#include "data_types.h"

DataNode::DataNode(std::string&& nodeName, DataType dataType) {
    setName(std::move(nodeName));
    type = dataType;
}

DataType DataNode::getType() const noexcept{
    return type;
}

void DataNode::setName(std::string&& n){
    name = n;
}

std::string DataNode::nameToString(){
    std::string nameStr;

    // If name is not ""
    if(!name.empty()) {
        nameStr += name;
        nameStr += " : ";
    }

    return nameStr;
}