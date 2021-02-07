// Copyright 2021 Pavlova D.
#include "Student.h"

void Student::addToGroup(Group *_group) { this->group_ = _group; }

void Student::addMark(int mark) { this->marks.push_back(mark); }

double Student::getAverageMark() {
  int sum = 0;
  for (auto &mark : this->marks)
    sum += mark;
  return double(sum) / this->marks.size();
}

bool Student::isHeadOfGroup() const { return group_->getHead().id == id; }