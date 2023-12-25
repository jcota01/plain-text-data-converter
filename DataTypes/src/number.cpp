//
// Created by 01jac on 23/12/2023.
//

#include "data_types.h"

Number::Number(std::string nodeName, int num) : DataNode(std::move(nodeName)) {
    value = num;
}

std::unique_ptr<Number> Number::create(std::string nodeName, int num){
    return std::unique_ptr<Number>(new Number(nodeName, num));
}

[[nodiscard]] std::string Number::toString() {
    std::string str = nameToString();
    str += std::to_string(value);

    return str;
}