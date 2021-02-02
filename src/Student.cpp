//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include <stdio.h>
#include <iostream>

#include "Student.h"
#include "Group.h"


void Student::addMark(int mark) {
  this->marks_.push_back(mark);
}

void Student::addToGroup(Group* group) {
  this->group_ = group;
}

Group Student::getGroup() const {
  Group copy;
  if (this->group_ != nullptr)
    Group copy (*(this->group_));
  return copy;
}

std::vector<int> Student::getMarks() const {
  std::vector<int> copy (this->marks_);
  return copy;
}

bool Student::isHeadOfGroup() const {
  return (this->group_->head_ == this);
}

float Student::getAverageMark() const {
  float sum = 0;
  for (int i = 0; i < this->marks_.size(); i++) {
    sum += (float)this->marks_[i];
  }
  if (this->marks_.size() != 0)
    return sum/this->marks_.size();
  else
    return 0.0;
}
