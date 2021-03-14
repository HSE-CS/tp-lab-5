// Copyright 2021 Grachev Alexander

#include "../include/Student.h"
#include "../include/Group.h"

Student::Student(unsigned int id, const std::string& name) {
    this->id = id;
    this->name = name;
}

void Student::setId(int newId) {
    id = newId;
}

int Student::getId() {
    return id;
}

void Student::setName(std::string newName) {
    name = newName;
}

std::string Student::getName() {
    return name;
}

void Student::addMark(int mark) {
    marks.push_back(mark);
}

double Student::getMidMark() {
    double result = 0;
    for (double mark : marks) result += mark;
    return marks.empty() ? 0 : result / marks.size();
}

void Student::addGroup(Group group) {
    this->group = &group;
    group.addStudent(*this);
}

Group &Student::getGroup() {
    return* group;
}
