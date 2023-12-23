//
// Created by 01jac on 23/12/2023.
//

#include "data_types.h"
#include <stdexcept>
#include <utility>

List::List(std::string nodeName) : DataNode(std::move(nodeName)){}

void List::addChild(DataNode *node) {
    values.push_back(node);
}

size_t List::size() {
    return values.size();
}

DataNode& List::operator[](int index){
    if (index < 0 || index >= values.size()){
        throw std::out_of_range("Index is out of range.");
    }
    return *values[index];
}

[[nodiscard]]std::string List::toString(){
    std::string str = nameToString();
    str += "\n\t[\n";
    for (auto & elem: values){
        str += "\t\t";
        str += elem->toString();
        str += '\n';
    }
    str += "\t]";

    return str;
}