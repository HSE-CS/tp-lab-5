// Copyright 2021 Artem Danyaev
#include "Student.h"

void Student::addToGroup(Group *gr) { group = gr; }
void Student::addMark(unsigned int mark) { marks.push_back(mark); }
float Student::getAverageMark() {
  if (marks.empty()) {
    return 0;
  }
  float c = 0;
  for (unsigned int m : marks) {
    c += m;
  }
  c /= marks.size();
  return c;
}
Student::Student(unsigned int i, std::string &f) : id(i), fio(f) {}

bool Student::isHeadOfGroup() { return group->head->id == id; }

unsigned int Student::getId() { return id; }
std::string Student::getFio() { return fio; }
