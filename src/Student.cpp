// Copyright 2021 Stolbov Yaroslav

#include "Student.h"
#include <iostream>
#include <numeric>

int Student::userId = 1;

Student::Student(std::string fio) {
    this->id = userId;
    this->fio = fio;
    Student::userId++;
}

void Student::addGroup(Group group) {
    this->group = &group;
    group.addStudent(*this);
}

void Student::addMark(int mark) {
    marks.push_back(mark);
}

double Student::getMiddleMark() {
    double result = 0;
    for (double mark : marks) result += mark;
    return result / marks.size();
}

int Student::getId() const {
    return id;
}

void Student::setId(int id) {
    Student::id = id;
}

const std::string &Student::getFio() const {
    return fio;
}

void Student::setFio(const std::string &fio) {
    Student::fio = fio;
}

const Group &Student::getGroup() const {
    return* group;
}

const std::vector<int> &Student::getMarks() const {
    return marks;
}

void Student::setMarks(const std::vector<int> &myMarks) {
    Student::marks = myMarks;
}
