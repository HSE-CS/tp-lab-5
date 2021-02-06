// Copyright 2021 Khoroshavina Ekaterina

#include "Student.h"

void Student::addMark(int mark) {
    this->marks.push_back(mark);
}

void Student::addToGroup(Group* group) {
    this->group = group;
    group->addStudent(this);
}

Student::Student(int id, std::string FIO) {
    this->id = id;
    this->fio = std::move(FIO);
    this->group = nullptr;
}

Student::Student(int id, std::string fio, Group* group) {
    this->id = id;
    this->fio = std::move(fio);
    this->group = group;
}

// Student::~Student() {
//     this->id = 0;
//     this->fio.clear();
//     this->marks.clear();
//     this->group = nullptr;
// }

int Student::getId() const {
    return this->id;
}

const std::string Student::getFIO() const {
    return this->fio;
}

Group* Student::getGroup() const {
    return this->group;
}

double Student::getAverageMark() {
    if (this->marks.empty()) {
        return 0.0;
    } else {
        double result = 0.0;
        int size = 0;
        for (int mark : this->marks) {
            result += mark;
            size++;
        }
        result /= size;
        return result;
    }
}

bool Student::isHeadOfGroup() {
    if ((this->group != nullptr) && (this->group->getHead() == this)) {
        return true;
    }
    return false;
}
