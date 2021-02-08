// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 06.02.2021.
//

#include "Student.h"
#include "Group.h"

Student::Student(unsigned int id, std::string fio,
                 std::vector<int> marks, Group *group) {
    this->fio = std::move(fio);
    this->id = id;
    this->group = group;
    this->isHead = false;
    this->marks = std::move(marks);
}

Student::Student(unsigned int id, std::string fio, Group *group) {
    this->fio = std::move(fio);
    this->id = id;
    this->group = group;
    this->isHead = false;
}

double Student::getAvrMark() const {
    double result = 0;
    for (auto n : marks)
        result += n;
    if (marks.empty()) {
        return 0;
    } else {
        return result / marks.size();
    }
}

bool Student::isHeadGroup() const {
    return this->isHead;
}

void Student::addToGroup(Group *valueGroup) {
    this->group = valueGroup;
}

void Student::addMark(int mark) {
    marks.push_back(mark);
}

void Student::addHead() {
    this->isHead = true;
}




