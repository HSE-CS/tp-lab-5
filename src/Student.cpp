// Copyright 2021 Bogomazov
#include <vector>
#include <numeric>
#include "../include/Student.h"

void Student::addMark(int mark) {
    _marks.push_back(mark);
}

float Student::calculateMeanMark() {
    return std::accumulate(_marks.begin(), _marks.end(), 0) / _marks.size();
}
