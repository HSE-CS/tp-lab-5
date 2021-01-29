// Copyright 2020 Dmitry Vargin

#include <iostream>
#include <string>

#include "Student.h"
#include "Group.h"
#include "Deanary.h"

int main() {
    Student *student = new Student(0, "Dima");
    std::cout << student->getFio() << " " << student->getId() << std::endl;
    student->addMark(4);
    student->addMark(5);
    std::vector<int> m = student->getMarks();
    for (int i: m)
        std::cout << i << " ";
    std::cout << std::endl << student->getAveragemark();
    return 0;
}
