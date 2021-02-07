// Copyright 2020 Dumarevskaya
#include "Student.h"

void Student::addToGroup(Group* name_group) {
  group = name_group;
  name_group->students.push_back(this);
}

void Student::addmark(uint64_t mark) {
  marks.push_back(mark);
}

double Student::getAveragemark() {
  if (marks.empty()) {
    return 0;
  }
  double average = 0;
  for (auto i : marks) {
    average +=  i;
  }
  return average / marks.size();
}

bool Student::isHeadGroup() {
  if (group->head == this) {
    return true;
  } else {
    return false;
  }
}
