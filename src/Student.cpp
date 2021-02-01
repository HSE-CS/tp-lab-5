// Copyright 2021 valvarl

#include "Student.h"

void Student::addToGroup(Group *_group) {
    group = _group;
}

void Student::addmark(int mark) {
    marks.push_back(mark);
}

int Student::getId() const {
    return id;
}

const std::string &Student::getName() const {
    return fio;
}

double Student::getAverageMark() {
    return static_cast<double>(accumulate(marks.begin(), marks.end(), 0))
    / marks.size();
}

bool Student::isHeadOfGroup() {
    return group->getHead().id == id;
}
