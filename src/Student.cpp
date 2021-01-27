// Copyright 2020 Stanislav Stoianov

#include "../include/Student.h"
#include <utility>

Student::Student(int id, std::string fullname) {
  this->id = id;
  this->fullname = std::move(fullname);
  this->group = nullptr;
}

Student::~Student() {
  this->id = 0;
  this->fullname.clear();
  this->group = nullptr;
  this->marks.clear();
}

void Student::addToGroup(Group *g) {
  this->group = g;
}

void Student::addMark(int16_t mark) {
  marks.push_back(mark);
}

double Student::getAverageMark() {
  double accum = 0.0;
  for (unsigned int mark : this->marks) {
    accum += mark;
  }
  return this->marks.empty() ? 0.0 : accum / this->marks.size();
}

bool Student::isHeadOfGroup() {
  return this->group != nullptr && this->group->getHead() == this;
}

int Student::getId() const {
  return id;
}

const std::string &Student::getFullname() const {
  return fullname;
}

Group *Student::getGroup() const {
  return group;
}

const std::vector<int16_t> &Student::getMarks() const {
  return marks;
}
