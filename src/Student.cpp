// Copyright 2021 Kuznetsov Mikhail
#include "Student.h"

Student::Student(unsigned int _id, std::string _fio) {
  id = _id;
  fio = _fio;
}

void Student::addToGroup(Group *_group) {
  group = _group;
  if (group != nullptr)
    group->addStudent(this);
}

void Student::addMark(int _mark) {
  marks.push_back(_mark);
}

float Student::getAverage() {
  int sum = 0;
  for (auto m : marks) {
    sum += m;
  }
  return marks.size() ? (float)sum / marks.size() : 0;
}

unsigned int Student::getId() {
  return id;
}

std::string Student::getFio() {
  return fio;
}
/*
bool Student::isHeadOfGroup() {
  return this == this->group->
}
*/

