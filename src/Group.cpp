// Copyright 2021 Bogomazov
#include<iostream>
#include<string>
#include "../include/Group.h"
#include "../include/Student.h"


std::string Group::getTitle() {
    return _title;
}
std::string Group::getSpec() {
    return _spec;
}
Student* Group::getHeadman() {
    return _head;
}
void Group::setTitle(std::string title) {
    _title = title;
}
void Group::setSpec(std::string spec) {
    _spec = spec;
}
// Group Group::createGroup(std::string title) {

// }
void Group::addStudentToGroup(Student* student) {
    students.push_back(student);
}

void Group::chooseHeadman(Student* student) {
    _head = student;
}

Student* Group::findStudent(std::string fio) {
    for (unsigned int i = 0; i < students.size(); i++) {
        if (students[i]->getFio().compare(fio) == 0)
            return students[i];
    }
    return NULL;
}

float Group::calculateMeanMark() {
    float total = 0;
    for (unsigned int i = 0; i < students.size(); i++) {
        int sum = 0;
        for (unsigned int j = 0; j < students[i]->getMarks().size(); j++)
            sum += students[i]->getMarks()[j];
        total += sum / students[i]->getMarks().size();
    }
    return total;
}
bool Group::removeStudentFromGroup(Student* student) {
    for (unsigned int i = 0; i < students.size(); i++) {
        if (students[i]->getId() == student->getId()) {
            students.erase(students.begin() + i);
            return true;
        }
    }
    return false;
}
