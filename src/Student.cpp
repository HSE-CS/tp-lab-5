// Copyright 2020 S. BOR
#include "Student.h"

Student::Student(int id, std::string fio) {
  this->id = id;
  this->fio = fio;
  this->group = nullptr;
}

bool Student::isHeadOfGroup() {
  if (this->group->head == this)
    return true;
  return false;
}

double Student::getAvarageMark() {
  int aver = 0;
  for (auto mark : marks)
    aver += mark;
  return marks.size() ? aver / static_cast<double> marks.size() : 0;
}

void Student::addToGroup(Group *group) {
  this->group = group;
}

void Student::addMark(int mark) {
  if (mark >= 1 && mark <= 10)
    marks.push_back(mark);
}
