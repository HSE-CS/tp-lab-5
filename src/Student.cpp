// Copyright 2021 mkhorosh
#include "Student.h"

double Student::getAverageMark() {
  double sum = 0;
  int n = marks.size();
  for (int i = 0; i < n; i++) {
    sum += marks[i];
  }
  return sum / n;
}

bool Student::isHeadOfGroup() {
  // берём группу по ссылке и просим её старосту, а потом проверяем он ли
  return false;
}

void Student::addToGroup(Group* new_group) {
  this->group=new_group;
}

void Student::addMark(int new_mark) {
  this->marks.push_back(new_mark);
}
