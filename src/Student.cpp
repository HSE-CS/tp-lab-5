//  Copyright 2021 dmitrycvetkov2000

#include "Student.h"
#include "Group.h"

#include <numeric>

Student::Student(int id, std::string name) : id(id), name(std::move(name)) {
}

void Student::addToGroup(Group* group) {
    group->addStudent(this);
    this->group = group;
}

void Student::addMark(int mark) {
    marks.push_back(mark);
}

double Student::getAverageMark() const {
    return std::accumulate(std::begin(marks), std::end(marks), 0)
        / static_cast<double>(marks.size());
}

bool Student::isHeadOfGroup() const {
    return group->headId == id;
}
