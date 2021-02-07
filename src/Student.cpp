// Copyright 2021 Egor Buzanov

#include "../include/Student.h"

Student::Student(int _id, std::string _fio) {
  id = _id;
  fio = _fio;
}

void Student::AddToGroup(Group* _group) { group = _group; }

void Student::AddMark(int _mark) { marks.push_back(_mark); }

bool Student::isHeadOfGroup() {
  if (group->getHead() == this) {
    return true;
  }
  return false;
}

double Student::getAverageMark() {
  double average_mark = 0.0;
  for (const int& mark : marks) {
    average_mark += static_cast<double>(mark);
  }
  average_mark /= static_cast<double>(marks.size());
  return average_mark;
}

int Student::getId() { return id; }

std::string Student::getFio() { return fio; }
