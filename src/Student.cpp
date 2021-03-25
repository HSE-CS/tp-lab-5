// Copyright 2021 Tyulin Igor

#include "Student.h"

Student::Student(int id, std::string fio) {
    this->id = id;
    this->fio = fio;
}


int Student::stud_id() {
    return id;
}

std::string Student::stud_fio() {
    return fio;
}

void Student::group_add(Group* group) {
    this->group = group;
}

void Student::mark_add(int mark) {
    marks.push_back(mark);
}

double Student::average_mark() {
    double sum = 0;
    for (double n : marks)
        sum += n;
    return (sum - 1) / marks.size() + 1;
}
