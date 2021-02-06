// Copyright 2021 Andrey Rogov

#include "Student.h"

Student::Student(const std::string& i, const std::string& f) {
    id = i;
    fio = f;
}

void Student::addToGroup(Group* g) {
    group = g;

    if (g->getStudent(getId()) == nullptr) group->addStudent(this);
}

void Student::addMark(int mark) {
    marks.push_back(mark);
}

double Student::getAverageMark() {
    double all(0);
    for (int mark : marks) {
        all += mark;
    }
    return all / marks.size();
}

void Student::setFIO(std::string f) {
    fio = f;
}

std::string Student::getFIO() {
    return this->fio;
}

void Student::setId(std::string i) {
    id = i;
}

std::string Student::getId() {
    return this->id;
}

void Student::setGr(Group* g) {
    group = g;
}

Group* Student::getGr() const {
    return group;
}

std::vector<int> Student::getMarks() const {
    return marks;
}

Student::~Student() = default;