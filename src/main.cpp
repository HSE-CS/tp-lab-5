// Copyright 2020 Dmitry Vargin

#include <iostream>
#include <string>

#include "Student.h"
#include "Group.h"
#include "Deanary.h"

int main() {
    Deanery *deanery = new Deanery();
    deanery->createGroups("groupInput.txt");
    deanery->hireStudents("studInput.txt");
    deanery->addMarksToAll(5);

    Group *group1 = new Group("qwe");
    deanery->addGroup(group1);
    Student *student = new Student("NavalnyA");
    group1->addStudent(student);
    deanery->saveStaff();

    for (Group *group : deanery->getGroups()) {
        std::cout << group->getTitle() << "\n";
        for (Student *student : group->getStudents()) {
            std::cout << "\t" << student->getId() << " ";
            std::cout << student->getFio() << " ";
            std::cout << student->marksToString() << "\n";
        }
    }
}
