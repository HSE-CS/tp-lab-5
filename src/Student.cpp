// Copyright 2020 Dmitry Vargin

#include <string>
#include <vector>

#include "Student.h"

Student::Student(int id, std::string fio) {
    this->id = id;
    this->fio = std::move(fio);
    this->group = nullptr;
    this->marks = {};
};

int Student::getId() const {
    return this->id;
}

std::string Student::getFio() {
    return this->fio;
}

Group* Student::getGroup() {
    return this->group;
}

std::vector<int> Student::getMarks() {
    return this->marks;
}

void Student::addToGroup(Group *pgroup) {
    this->group = pgroup;
}

void Student::addMark(int mark) {
    this->marks.push_back(mark);
}

double Student::getAveragemark() {
    if (!this->marks.empty()) {
        int sum = 0;
        for (int mark: this->marks) {
            sum += mark;
        }
        return 1.0 * sum / this->marks.size();
    }
    return 0.0;
}

bool Student::isHeadOfGroup() {
    return this->group->getHead()->id == this->id;
}
