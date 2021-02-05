//  Copyright © 2021 Ksuvot. All rights reserved.

#include "Student.h"

bool Student::isHeadOfGroup() {
  return this->group->head == this ? true : false;
}

void Student::setMark(int mark) {
  if (mark > 0 && mark < 11)
    this->marks.push_back(mark);
}

double Student::getAverageMark() {
  if (!this->marks.empty()) {
    int sum = 0;
    for (int mark : this->marks) {
      sum += mark;
    }
    return sum / this->marks.size();
  }
  return 0;
}

void Student::setGroup(Group *group) {
  this->group = group;
}

Student::Student(int id, std::string fio) {
  this->id = id;
  this->fio = fio;
  this->group = nullptr;
}

int Student::GetId() const {
  return id;
}

Group *Student::GetGroup() const {
  return group;
}

const std::string &Student::GetFio() const {
  return fio;
}

const std::vector<int> &Student::GetMarks() const {
  return marks;
}
