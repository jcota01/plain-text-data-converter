//
// Created by 01jac on 23/12/2023.
//

#include "data_types.h"

DataNode::DataNode(std::string&& nodeName, DataType dataType) {
    setName(std::move(nodeName));
    type = dataType;
}

DataType DataNode::getType() const{
    return type;
}

void DataNode::setName(std::string&& n){
    name = n;
}

std::string DataNode::nameToString(){
    std::string nameStr;
    nameStr += name;
    nameStr += " : ";

    return nameStr;
}