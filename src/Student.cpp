// Copyright 2021 TimurZaytsev

#include <Student.h>
#include "Group.h"

Student::Student(uint64_t _id, const std::string& _name, Group* g) :
    id(_id),
    name(_name),
    group(g)
{}

double Student::get_average_mark() const {
    double result = 0;
    for (auto n : marks)
        result += n;

    return !marks.empty() ? result / marks.size() : 0;
}

bool Student::is_head() const {
    if (group != nullptr && group->head == this)
        return true;
    else
        return false;
}

void Student::add_mark(int mark) {
    marks.push_back(mark);
}
