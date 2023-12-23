//
// Created by 01jac on 23/12/2023.
//

#include "data_types.h"
#include <stdexcept>

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

[[nodiscard]]std::string List::toString() const{
    std::string str;
    for (auto & elem: values){
        str += elem->toString();
        str += "; ";
    }
    return str;
}