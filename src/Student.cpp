// Copyright 2021 Igumnova Natasha
#include "Student.h"
#include <iostream>


void Student::addToGroup(Group* gr) {
    this->group = gr;
}
double Student::getAveragemark() {
    int sum = 0;
    if (marks.size()) {
        for (int i = 0; i < marks.size(); i++) {
            sum += (marks[i]);
        }
        return sum / marks.size();
    }
    return 0;
}

bool Student::isHeadOfGroup() {
    return (group != nullptr && group->head == this);
}

int Student::getId() {
    return this->id;
}
std::string Student::getFio() {
    return this->fio;
}
