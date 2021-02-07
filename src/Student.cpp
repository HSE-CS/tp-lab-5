// Copyright 2021 Kasyanov
#include "../include/Deanary.h"

Student::Student(int _id, std::string _fio, Group* _group) {
  id = _id;
  fio = _fio;
  group = _group;
  isHead = false;
  int i = rand() % 101 + 1;
  if (i <= 30) {
    skill = ABILITY::OK;
  } else if (i > 30 && i <= 70) {
    skill = ABILITY::GOOD;
  } else {
    skill = ABILITY::EXCELLENT;
  }
  AddToGroup(_group);
}

double Student::GetAverageMark() const {
  double ans = 0;
  for (auto m : marks) {
    ans += m;
  }
  ans /= marks.size();
  return ans;
}

bool Student::IsHeadOfGroup() const { return isHead; }

void Student::AddMark(int m) { marks.push_back(m); }

void Student::AddToGroup(Group* group) { group->students.push_back(this); }

std::string Student::GetName() const { return fio; }
