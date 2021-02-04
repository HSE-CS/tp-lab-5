// Copyright 2021 soda

#include "Student.h"


void Student::addToGroup(Group* group) {
    this->group = group;
}

void Student::addmark(int mark) {
    marks.push_back(mark);
}

double Student::getAverageMark() {
    return static_cast<double>(accumulate(marks.begin(),
        marks.end(), 0) / marks.size());
}

int Student::getId() {
    return id;
}

const std::string& Student::getName() {
    return fio;
}

bool Student::isHeadOfGroup() {
    return group->getHead().id == id;
}

