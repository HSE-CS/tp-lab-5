// Copyright 2021 Shatilov Victor
#include "Student.h"

#include <utility>

Student::Student(int id_, std::string fio_) : id(id_), fio(std::move(fio_)) { }

void Student::addToGroup(Group* group) { this->group = group; }
void Student::rate(int mark) { marks.push_back(mark); }
float Student::getAverageMark() {
    if (marks.empty())
        return 0;

    float sum = 0;
    for (auto m : marks)
        sum += (float) m;

    return sum / marks.size();
}
int Student::getId() { return id; }
std::string Student::getFio() { return fio; }
