// Copyright [2020] <Olesya Nikolaeva>

#include "Student.h"

Student::Student(std::string ID, std::string FIO) {
    this->fio = new char[ID.length() + 1];
    this->id = ID;
    this->fio = new char[FIO.length() + 1];
    this->fio = FIO;
    this->group = nullptr;
}

void Student::groupIs(Group* G) {
    this->group = G;
    G->students.push_back(this);
}

void Student::addMark(uint64_t mark) {
    this->marks.push_back(mark);
}

int Student::averageMark() {
    int average = 0;
    for (int n : marks)
        average += n;
    return (average - 1) / marks.size() + 1;
}

std::string Student::getGroup() {
    return name->group->title;
}
