//
// Created by 01jac on 23/12/2023.
//

#include "data_types.h"

#include <utility>

DataNode::DataNode(std::string nodeName) {
    setName(std::move(nodeName));
}

void DataNode::setName(std::string n){
    name = std::move(n);
}

std::string DataNode::nameToString(){
    std::string nameStr;
    nameStr += name;
    nameStr += " : ";

    return nameStr;
}