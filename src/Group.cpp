// Copyright 2021 Bogomazov
#include<iostream>
#include<string>
#include "../include/Group.h"
#include "../include/Student.h"

// Group Group::createGroup(std::string title) {

// }
void Group::addStudentToGroup(Student* student) {
    students.push_back(student);
}

void Group::chooseHeadman(Student* student) {
    head = student;
}

Student* Group::findStudent(std::string fio) {
    for (unsigned int i = 0; i < students.size(); i++) {
        if (students[i]->fio.compare(fio) == 0)
            return students[i];
    }
    return NULL;
}

float Group::calculateMeanMark() {
    float total = 0;
    for (unsigned int i = 0; i < students.size(); i++) {
        int sum = 0;
        for (unsigned int j = 0; j < students[i]->marks.size(); j++)
            sum += students[i]->marks[j];
        total += sum / students[i]->marks.size();
    }
    return total;
}
// bool removeStudentFromGroup(Student* student) {

// }
