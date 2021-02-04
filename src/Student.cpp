// Copyright 2021 Bodrov Egor
#include "Student.h"

Student::Student(int id_, const std::string& name_)
    : id {id_}, fio {name_}
{
}

void Student::addToGroup(Group* group_) {
    group = group_;
}

void Student::addmark(int mark) {
    marks.push_back(mark);
}

double Student::getAveragemark() {
    double res {0.0};
    for (auto i : marks) {
        res += i;
    }
    return static_cast <double> (res / marks.size());
}

int Student::get_id() {
    return id;
}

std::string& Student::get_name() {
    return fio;
}

bool Student::isHeadOfGroup() {
    if (group->head == this)
        return true;
    return false;
}
