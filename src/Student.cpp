// Copyright 2020 Uskova
#include "Student.h"

Student::Student() {
    this->id = 0;
    this->fio = "";
    this->group = NULL;
    std::vector<int> marks_;
    this->marks = marks_;
}

Student::Student(int id_, std::string fio_) {
    this->id = id_;
    this->fio = fio_;
    this->group = NULL;
    std::vector<int> marks_;
    this->marks = marks_;
}

void Student::addToGroup(Group* group) {
    this->group = group;
}

void Student::addMark(int mark) {
    this->marks.push_back(mark);
}

float Student::getAverageMark() {
    float avmark = 0.0;
    for (int i = 0; i < this->marks.size(); i++) {
        avmark += marks.at(i);
    }
    avmark = avmark / this->marks.size();
    return avmark;
}

bool Student::isHeadOfGroup() {
    if ((this->group != NULL) && ((this->group)->getHead() == this)) {
        return true;
    } else {
        return false;
    }
}

std::string Student::getFio() {
    return this->fio;
}


int Student::getId() {
    return this->id;
}
