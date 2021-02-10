// copyright Toliman 2021

#include "../include/Student.h"

#include <utility>

Student::Student(int idParam, std::string fioParam) {
    this->id = idParam;
    this->fio = std::move(fioParam);
    this->group = nullptr;
}

void Student::setGroup(Group &groupParam) {
    this->group = &groupParam;
}

void Student::addMark(int mark) {
    this->marks.push_back(mark);
}

float Student::getMiddleMark() {
    float middle(.0);
    for (auto x : this->marks)
        middle += x;
    if (!(this->marks.empty()))
        middle /= (float) (this->marks.size());
    return middle;
}

Group *Student::getGroup() {
    return this->group;
}

std::string Student::getFio() {
    return this->fio;
}

int Student::getId() const {
    return this->id;
}

void Student::str() {
    std::cout << this->getFio() + " (id: " + std::to_string(this->getId()) + ")";
}

void Student::leaveGroup() {
    this->group = nullptr;
}
