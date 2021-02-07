// Copyright 2021 ArinaMonicheva

#include "Student.h"

Student::Student(unsigned newId = 0, std::string fullName = "") {
  id = newId;
  fio = fullName;
  group = NULL;
  isHead = false;
}

void Student::addToGroup(Group* newGroup) {
  group = newGroup;
}

void Student::addMark(int newMark) {
  marks.push_back(newMark);
}

double Student::getAverageMark() {
  int averageMark = 0, j = 0;

  for (auto i : marks) {
    averageMark += i;
    j++;
  }

  return (static_cast<double>(averageMark)) / j;
}

bool Student::isHeadOfGroup() {
  return isHead;
}
