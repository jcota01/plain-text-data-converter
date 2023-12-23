#include <iostream>
#include "data_types.h"

int main() {
    auto* str = new String("hello", "str1");

    auto* obj = new Object("obj1");
    obj->addChild(str);

    auto* str2 = new String("goodbye", "str2");

    auto* list = new List("list1");
    list->addChild(obj);
    list->addChild(str2);

    std::cout << list->toString() << std::endl;


    return 0;
}
