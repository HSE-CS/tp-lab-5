// Copyright 2021 Lab_5 TiNa
#include "Student.h"
#include <iostream>

Student::Student(int id, std::string fio) {
    this->id = id;
    this->fio = fio;
}

void Student::addToGroup(Group* group) {
    this->group = group;
}

void Student::addMark(int mark) {
    this->marks.push_back(mark);
}

double Student::getAveragemark() {
    double sum = 0.0;
    for (int i = 0; i < this->marks.size(); i++) {
        sum += this->marks[i];
    }
    if (marks.size()) {
        return sum / this->marks.size();
    }
}

int Student::getId() {
    return id;
}

std::string Student::getFio() {
    return fio;
}

Group* Student::getGroup() {
    return group;
}
