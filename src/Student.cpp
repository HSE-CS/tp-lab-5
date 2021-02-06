// Copyright 2021 MalininDmitry
#include "Group.h"
#include "Student.h"

Student::Student(int id, std::string fio) {
    this->id = id;
    this->fio = fio;
}
Student::~Student() {
    id = 0;
    group = nullptr;
    fio.clear();
    marks.clear();
}
double Student::getAveragemark() {
    double average = 0;
    for (int i = 0; i < this->marks.size(); i++)
        average += this->marks[i];
    if (this->marks.size())
        return (average/this->marks.size());
    return 0.0;
}
int Student::getId() {
    return this->id;
}

std::string Student::getFio() {
    return this->fio;
}

Group * Student::getGroup() {
    return this->group;
}

void Student::addToGroup(Group * groupName) {
    this->group = groupName;
}

void Student::addMark(int mark) {
    marks.push_back(mark);
}

void Student::changeId(int index) {
    this->id = index;
}
