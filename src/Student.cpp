// Copyright 2021 

#include "Student.h"

Student::Student(int _id, std::string _fio) {
  id = _id;
  fio = _fio;
}

void Student::Add2Group(Group* _group) { group = _group; }

void Student::AddMark(int _mark) { marks.push_back(_mark); }

bool Student::isleadOfGroup() {
  if (group != nullptr && group->getlead() == this) {
    return true;
  }
  return false;
}

double Student::getAverageMark() {
  if (marks.size() == 0) {
    return 0.0;
  }
  double average_mark = 0.0;
  for (const int& mark : marks) {
    average_mark += static_cast<double>(mark);
  }
  average_mark /= static_cast<double>(marks.size());
  return average_mark;
}

int Student::getId() { return id; }

std::string Student::getFio() { return fio; }