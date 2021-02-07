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

std::vector<Student*> Group::getStudents() {
    return _students;
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
    student->setGroup(this);
    _students.push_back(student);
}

void Group::chooseHeadman(Student* student) {
    _head = student;
}

Student* Group::findStudent(std::string fio, int id) {
    if (!fio.empty()) {
        for (unsigned int i = 0; i < _students.size(); i++) {
        if (_students[i]->getFio().compare(fio) == 0)
            return _students[i];
        }
        return NULL;
    } else {
        for (unsigned int i = 0; i < _students.size(); i++) {
        if (_students[i]->getId() == id)
            return _students[i];
        }
        return NULL;
    }
}

float Group::calculateMeanMark() {
    float total = 0;
    for (unsigned int i = 0; i < _students.size(); i++) {
        int sum = 0;
        for (unsigned int j = 0; j < _students[i]->getMarks().size(); j++)
            sum += _students[i]->getMarks()[j];
        total += sum / _students[i]->getMarks().size();
    }
    total /= static_cast<float>(_students.size());
    return total;
}

bool Group::removeStudentFromGroup(Student* student) {
    for (unsigned int i = 0; i < _students.size(); i++) {
        if (_students[i]->getId() == student->getId()) {
            _students.erase(_students.begin() + i);
            student->setGroup(NULL);
            return true;
        }
    }
    return false;
}

bool Group::isEmpty() {
    return _students.empty();
}
