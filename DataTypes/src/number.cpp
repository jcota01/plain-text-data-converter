//
// Created by 01jac on 23/12/2023.
//

#include "data_types.h"

Number::Number(int num) {
    value = num;
}

[[nodiscard]] std::string Number::toString() const{
    return std::to_string(value);
}