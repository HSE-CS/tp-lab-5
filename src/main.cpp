// Copyright 2020 Dmitry Vargin

#include <iostream>
#include <string>

#include "Student.h"
#include "Group.h"
#include "Deanary.h"

int main() {
    /*
    Student *student = new Student(0, "Dima");
    std::cout << student->getFio() << " " << student->getId() << std::endl;
    student->addMark(4);
    student->addMark(5);
    std::vector<int> m = student->getMarks();
    for (int i: m)
        std::cout << i << " ";
    std::cout << std::endl << student->getAveragemark();
    return 0;
     */

    Deanery *deanery = new Deanery();
    deanery->createGroups("groupInput.txt");
    deanery->hireStudents("studInput.txt");
    deanery->addMarksToAll(5);

    Group *group1 = new Group("qwe");
    deanery->addGroup(group1);
    Student *student = new Student("NavalnyA");
    group1->addStudent(student);
    for (Student *student1: group1->getStudents()) {
        std::cout << student1->getGroup()->getTitle();
    }
    deanery->saveStaff();
    /*
    for (Group *group: deanery->getGroups()) {
        std::cout << group->getTitle() << "\n";
        for (Student *student: group->getStudents()) {
            std::cout << "\t" << student->getId() << " ";
            std::cout << student->getFio() << " ";
            std::cout << student->marksToString() << "\n";
        }
    }
     */
    /*
    std::string s = "23 ДумаревскаяТ PI2";
    std::string tmp = s.substr(s.find(' ')+1, s.length());
    s = tmp.substr(0, tmp.find(' '));
    std::cout << s;
     */
}
