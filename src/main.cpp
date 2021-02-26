// Copyright 2021 Stolbov Yaroslav
#include <iostream>
#include <fstream>
#include <Deanary.h>
#include "Group.h"
int main() {
    Student student = Student("Kek");
    student.addMark(10);
    Student student2 = Student("Pek");
    student2.addMark(5);
    Group group = Group("hse", "000");
    group.addStudent(student);
    group.addStudent(student2);
    double res = 7.5;
    std::cout << group.groupMiddleMark();
    return 0;
}
