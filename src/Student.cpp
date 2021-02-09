// Copyright 2021 Shirokov Alexander

#include "Student.h";
#include "Group.h";

Student::Student(int ID, const std::string& FIO) {
  id = ID;
  fio = FIO;
}

void Student::addToGroup(Group* gr) {
  group = gr;
}

void Student::addmark(int mark) {
  marks.push_back(mark);
}

float Student::getAveragemark() {
  double res = 0.0;
  for (auto i : marks) {
    res += i;
  }
  return res;
}

bool Student::isHeadOfGroup() {
  return group->head == this;
}

int Student::getId() {
  return id;
}

std::string Student::getName() {
  return fio;
}
