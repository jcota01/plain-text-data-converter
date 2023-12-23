#include <iostream>
#include "data_types.h"

int main() {
    auto* str = new String();
    str->set("hello");

    auto* obj = new Object();
    obj->setChild(str);

    auto* str2 = new String("goodbye");

    auto* list = new List();
    list->addChild(obj);
    list->addChild(str2);

    std::cout << list->toString() << std::endl;

    return 0;
}
