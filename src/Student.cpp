//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include <stdio.h>
#include <iostream>

#include "Student.h"
#include "Group.h"

//Student::Student(int new_ID, std::string new_fio):
//ID_(new_ID), fio_(new_fio), ID(ID_), fio(fio_), marks(marks_), group_(nullptr) {}

void Student::addMark(int mark) {
  this->marks_.push_back(mark);
}

void Student::addToGroup(Group* group) {
  this->group_ = group;
}

bool Student::isHeadOfGroup() const {
  return (this->group_->getHead() == this);
}

float Student::getAverageMark() const {
  float sum = 0;
  for (int i = 0; i < this->marks_.size(); i++) {
    sum += (float)this->marks_[i];
  }
  return sum/this->marks_.size();
}
