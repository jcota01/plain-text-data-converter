//
// Created by 01jac on 23/12/2023.
//

#include "data_types.h"

Object::Object(DataNode *obj) {
    value = obj;
}

Object::Object() {
    value = nullptr;
}

void Object::setChild(DataNode* obj){
    value = obj;
}

[[nodiscard]] std::string Object::toString() const{
    return (value) ? value->toString() : "";
}