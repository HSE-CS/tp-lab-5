// Copyright 2021 Sozinov Kirill
#include <Student.h>

Student::Student(unsigned id, std::string fio) {
    this->id = id;
    this->fio = fio;
}

Student::~Student() {
    delete this;
}

void Student::addToGroup(Group *group) {
    this->group = group;
}

void Student::addmark(size_t mark) {
    this->marks.push_back(mark);
}

double Student::getAverageMark() {
    unsigned sum = 0;
    if (marks.size() == 0) {
        return 0;
    } else {
        for (unsigned i = 0; i < marks.size(); ++i)
            sum += marks[i];
        return sum / marks.size();
    }
}

std::string Student::getFIO() {
    return fio;
}

unsigned Student::getID() {
    return id;
}

bool Student::isHeadOfGroup() {
    return isHead;
}

Group *Student::getGroup() {
    return group;
}
