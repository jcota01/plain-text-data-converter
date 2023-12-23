//
// Created by 01jac on 23/12/2023.
//

#include "data_types.h"

Number::Number(int num, std::string nodeName) : DataNode(std::move(nodeName)) {
    value = num;
}

[[nodiscard]] std::string Number::toString() {
    std::string str = nameToString();
    str += std::to_string(value);

    return str;
}