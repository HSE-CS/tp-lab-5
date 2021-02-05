// Copyright 2021 Andrey Bakurskii

#include <iostream>
#include <string>
#include "Group.h"
#include "Student.h"
#include "Deanary.h"



int main() {
    Deanary deanary;
    deanary.hireStudents(std::string("./data/DataStudents.txt"));
    deanary.createGroups(std::string("./data/DataGroup.txt"));
    deanary.addMarksToAll();
    deanary.getStatistics();

    // deanary.printGroups();

    float min_average_mark = 4.0;
    deanary.fireStudents(min_average_mark);
    deanary.saveStaff("./data/savedStaff.txt");

    // deanary.printStudents();

    return 0;
}
