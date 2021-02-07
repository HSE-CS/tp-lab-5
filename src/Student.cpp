// Copyright 2020 me
#include "../include/Student.h"

unsigned Student::count = 0;

void Student::addToGroup(Group *gr) {
    group = gr;
}

void Student::addMark(int mark) {
    marks.push_back(mark);
}

std::string Student::getFio() {
    return fio;
}

unsigned Student::getId() {
    return id;
}

float Student::getAveragemark() {
  double sum = 0.0;
  for (auto i : marks) {
    sum += i;
  }
  if (marks.size() == 0) return 0.0;
  return sum / marks.size();
}

bool Student::isHeadOfGroup() {
    return isHead;
}
