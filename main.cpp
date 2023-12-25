#include <iostream>
#include "data_types.h"

int main() {
    auto str = String::create("str1");
    auto obj = Object::create("obj1");

    str->set("hello");

    obj->addChild(std::move(str));

    auto str2 = String::create("str2");
    str2->set("goodbye");

    auto list = List::create("list1");
    list->addChild(std::move(obj));
    list->addChild(std::move(str2));

    std::cout << list->toString() << std::endl;
    std::cout << list->size() << std::endl;

    return 0;
}
