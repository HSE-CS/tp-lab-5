// Copyright 2021 Bogomazov
#include <vector>
#include <numeric>
#include "../include/Student.h"

void Student::addMark(int mark) {
    marks.push_back(mark);
}

float Student::calculateMeanMark() {
    return std::accumulate(marks.begin(), marks.end(), 0) / marks.size();
}
