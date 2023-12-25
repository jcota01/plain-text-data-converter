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