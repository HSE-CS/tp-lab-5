// Copyright [2021] <Nikita Semaev>
#include "../include/Student.h"
#include "../include/Group.h"

void Student::addToGroup(Group *group) {
    this->group = group;
}

void Student::addMark(uint8_t mark) {
    this->marks.push_back(mark);
}

float Student::averageMark() const {
    float &&result = 0;
    for (auto mark : this->marks) {
        result += mark;
    }
    result /= this->marks.size();
    return result;
}
