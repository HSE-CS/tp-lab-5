// Copyright 2021 mkhorosh
#include "Student.h"

Student::Student(std::string id, std::string fio) {
  this->id = id;
  this->fio = fio;
  this->group = nullptr;
  this->marks = {};
}

double Student::getAverageMark() {
  double sum = 0;
  int n = marks.size();
  for (int i = 0; i < n; i++) {
    sum += marks[i];
  }
  if (n == 0) {
    return 0;
  }
  return sum / n;
}

bool Student::isHeadOfGroup() {
  if (group != nullptr && id == group->head->id) {
    return true;
  }
  return false;
}

void Student::addToGroup(Group *new_group) {
  this->group = new_group;
}

void Student::addMark(int new_mark) {
  this->marks.push_back(new_mark);
}
