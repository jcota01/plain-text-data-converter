//
// Created by 01jac on 23/12/2023.
//

#include "data_types.h"
#include <stdexcept>

List::List(std::string&& nodeName) : DataNode(std::move(nodeName), DataType::LIST){}

std::unique_ptr<List> List::create(std::string&& nodeName){
    return std::unique_ptr<List>(new List(std::move(nodeName)));
}

void List::addChild(std::unique_ptr<DataNode>&& node) {
    values.push_back(std::move(node));
}

size_t List::size() {
    return values.size();
}

DataNode& List::operator[](int index){
    // Make sure there is an element at the index
    if (index < 0 || index >= values.size()){
        throw std::out_of_range("Index is out of range.");
    }
    return *values[index];
}

[[nodiscard]]std::string List::toString(){
    // Get "NAME : "
    std::string str = nameToString();
    str += "[ ";
    // Add each element from the list to the string
    for (auto & elem: values){
        str += elem->toString() + ", ";
    }
    str += "]";

    return str;
}