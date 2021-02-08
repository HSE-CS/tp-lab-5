// Copyright 2021 kostinandrey
#include "Student.h"
#include <utility>
#include <numeric>
Student::Student(int _id, std::string fio) {
    this->id = _id;
    this->fio = std::move(fio);
    this->group = nullptr;
    this->marks = std::vector<int>();
}

int Student::get_id() const {
    return id;
}

std::string Student::get_fio() {
    return fio;
}

void Student::add_to_group(Group* group) {
    this->group = group;
}

void Student::add_mark(int mark) {
    marks.push_back(mark);
}

double Student::get_average_mark() {
    double sum = std::accumulate(marks.begin(), marks.end(), 0);
    if (!marks.empty())
        return sum/marks.size();
    return 0;
}
