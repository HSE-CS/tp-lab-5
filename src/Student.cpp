#include "Student.h"

// Copyright 2020 Polina Lukicheva

Student::Student() {
  this->id = 0;
  this->fio = "";
  this->group = NULL;
  std::vector<int> marks_;
  this->marks = marks_;
}

Student::Student(int id, const std::string fio) {
  this->fio = fio;
  this->id = id;
  this->marks = std::vector<int>();
}

Student::~Student() {
}

void Student::add2Group(Group* group) {
  this->group = group;
}

int Student::getId() {
  return id;
}

std::string Student::getFio() {
  return fio;
}

void Student::addmark(int mark) {
  this->marks.push_back(mark);
}

double Student::averageMark() {
  double mean = 0;
  for (auto i : marks)
    mean += i;
  return (mean / marks.size());
}

bool Student::isHeadOfGroup() {
  return (group->getHead() == this);
}



