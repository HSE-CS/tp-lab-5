// Copyright 06.02.21 DenisKabanov

#include "Student.h"

Student::Student(unsigned int newid, std::string newfio) {
    this->id = newid;
    this->fio = newfio;
}

void Student::addToGroup(Group* togroup) {
    this->group = togroup;
    this->group->addStudent(this);
}

void Student::addMark(int newmark) {
    this->marks.push_back(newmark);
}

float Student::getAveragemark() {
    float allmarks = 0;
    int counter = 0;
    for (auto m : this->marks) {
        counter++;
        allmarks = allmarks + m;
    }
    if (counter != 0)
        return allmarks / counter;
    else
        return 0;
}

int Student::getId() {
    return this->id;
}

std::string Student::getFio() {
    return this->fio;
}

Group* Student::getGroup() {
    return this->group;
}

bool Student::isHeadOfGroup() {
    if (this == group->getHead())
        return true;
    else
        return false;
}
