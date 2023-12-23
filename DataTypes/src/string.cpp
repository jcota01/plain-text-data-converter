//
// Created by 01jac on 23/12/2023.
//

#include "data_types.h"

String::String() {
    value = nullptr;
}

String::String(const std::string &val) {
    value = std::make_unique<std::string>(val);
}

std::string String::toString() const{
    return (value) ? *value : "";
}
void String::set(const std::string& val){
    value = std::make_unique<std::string>(val);
}