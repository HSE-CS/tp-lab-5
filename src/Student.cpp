// Copyright 2021 soda

#include "Student.h"

void Student::addToGroup(Group* group) {
    this->group = group;
}

void Student::addmark(int mark) {
    marks.push_back(mark);
}

double Student::getAverageMark() {
    return (double)accumulate(marks.begin(), marks.end(), 0) / marks.size();
}


//
//const std::string& Student::getName() const {
//    return fio;
//}

//bool Student::isHeadOfGroup() {
//    return group->getHead().id == id;
//}

//int Student::getId() const {
//    return id;
//}