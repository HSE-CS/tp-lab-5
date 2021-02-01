// Copyright by JMax 2020

#include "Student.h"


Student::Student(const unsigned int id, const std::string &fio) {
    this->id = id;
    this->fio = fio;
    this->marks = std::vector<unsigned int>();
}

void Student::addToGroup(Group *group) {
    this->group = group;
}

void Student::removeFromGroup() {
    group = nullptr;
}

void Student::addMark(unsigned int mark) {
    marks.push_back(mark);
}

double Student::getAverageMark() {
    if (numOfMarks() == 0)
        return 0;
    return static_cast<double>(sumOfMarks())/numOfMarks();
}

unsigned int Student::sumOfMarks() {
    unsigned int sum = 0;
    for (auto mark : marks) {
        sum += mark;
    }
    return sum;
}

unsigned int Student::numOfMarks() {
    return marks.size();
}

bool Student::isHeadOfGroup() {
    if (group != nullptr) {
        return group->getHead() == this;
    } else {
        return false;
    }
}

std::string Student::getFio() const {
    return fio;
}

unsigned int Student::getId() const {
    return id;
}

