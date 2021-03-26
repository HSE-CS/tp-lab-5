// Copyright 2021 Bekina Svetlana
#include "Student.h"

Student::Student() {}
Student::~Student() {
    marks.clear();
}
Student::Student(std::string new_id, std::string new_fio, Group* new_group) {
    id = new_id;
    fio = new_fio;
    group = new_group;
}

void Student::addToGroup(Group* new_group) {
    group = new_group;
}

bool Student::isHeadOfGroup() const {
    return group->getHead() == this;
}
void Student::addmark(int mark) {
    marks.push_back(mark);
}

double Student::getAveragemark() const {
    return static_cast<double>(std::accumulate(marks.begin(),
        marks.end(), 0) / marks.size());
}

std::string Student::getFio() const {
    return fio;
}

std::string Student::getId() const {
    return id;
}

std::vector<int> Student::getmarks() const {
    return marks;
}

