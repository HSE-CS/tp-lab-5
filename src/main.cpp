// Copyright 2021 Grachev Alexander

#include <iostream>
#include "../include/Deanary.h"
#include "../include/Group.h"
#include "../include/Student.h"

int main() {
    Student a(2312, "Grachev A.E.");

    std::cout << a.getId() << std::endl;
    a.setId(2112);
    std::cout << a.getId() << std::endl;

    std::cout << a.getName() << std::endl;
    a.setName("Grachev Alexander");
    std::cout << a.getName() << std::endl;

    a.addMark(10);
    a.addMark(9);
    a.addMark(5);
    a.addMark(8);
    std::cout << a.getMidMark() << std::endl;

    return 0;
}
