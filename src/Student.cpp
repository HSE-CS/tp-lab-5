// Copyright 2021 Bogomazov
#include <vector>
#include <numeric>
#include "../include/Student.h"

int Student::getId() {
    return _id;
}

std::string Student::getFio() {
    return _fio;
}
std::vector<int> Student::getMarks() {
    return _marks;
}
void Student::setId(int id) {
    _id = id;
}
void Student::setFio(std::string fio) {
    _fio = fio;
}

void Student::addMark(int mark) {
    _marks.push_back(mark);
}

float Student::calculateMeanMark() {
    return std::accumulate(_marks.begin(), _marks.end(), 0) / _marks.size();
}
