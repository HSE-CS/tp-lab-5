  // Copyright 2021 Nikolaev Ivan

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"

int main() {
    setlocale(LC_ALL, "");
    std::vector<int> vec = { 5, 5, 5, 5 };
    Student stud1(1, "Nikolaev I A", vec);
    Group PI();
    std::cout << stud1.getAveragemark() << std::endl;
    Deanary deanary;
    deanary.readFile();
    deanary.addMarksToAll();
    deanary.addMarksToAll();
    deanary.addMarksToAll();
    deanary.addMarksToAll();
    deanary.initHeads(deanary.findGroup("19PI1"));
    deanary.initHeads(deanary.findGroup("19PI2"));
    deanary.moveStudents(deanary.findGroup("19PI1"),
        deanary.findGroup("19PI2"), deanary.findStudent(5));
    deanary.fireStudents(deanary.findStudent(5));
    std::map<int, double> list = deanary.getStatistics();
    deanary.printStatistics(list);
    deanary.saveStaff();
    return 0;
}
