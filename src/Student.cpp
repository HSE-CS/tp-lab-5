// Copyright 2021 Bogomazov
#include <vector>
#include <numeric>
#include "../include/Student.h"
#include "../include/Group.h"

int Student::getId() {
    return _id;
}

std::string Student::getFio() {
    return _fio;
}

std::vector<int> Student::getMarks() {
    return _marks;
}

Group* Student::getGroup() {
    return _group;
}

void Student::setId(int id) {
    _id = id;
}

void Student::setFio(std::string fio) {
    _fio = fio;
}

void Student::setGroup(Group *group) {
    _group = group;
}

void Student::addMark(int mark) {
    _marks.push_back(mark);
}

float Student::calculateMeanMark() {
    return static_cast<float>(std::accumulate(_marks.begin(),
         _marks.end(), 0)) / static_cast<float>(_marks.size());
}

void Student::enrollInGroup(Group* group) {
    group->addStudentToGroup(this);
}
