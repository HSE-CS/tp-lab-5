// Copyright 2021 MalininDmitry
#include <iostream>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"


int main() {
    unsigned int id = 11;
    std::string fio = "Ddsa Sfdsfsdf";
    Student student1(id, fio);
    unsigned int id2 = 12;
    std::string fio2 = "Ddsa Sfdsfsd2332";
    Student student2(id2, fio2);
    std::string spec = "Color";
    std::string title = "Red";
    Group group(title, spec);
    group.addStudent(&student1);
    group.addStudent(&student2);
    std::cout << group.isEmpty() << std::endl;

    Deanary deanery("DataGroup.txt");
    deanery.hireStudents("DataStudent.txt");
    deanery.addMarksToAll(4);
    deanery.addMarksToAll(5);
    deanery.outputToConsole();

    deanery.fireStudents();
    deanery.outputToConsole();

    deanery.getStatistics("stat.txt");
    deanery.saveStaff("DataGroup.txt", "DataStudent.txt");

    return 0;
}
