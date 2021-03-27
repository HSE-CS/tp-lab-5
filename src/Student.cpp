// Copyright 2021 KarMashanova
#include "Student.h"
#include <numeric>

void Student::addToGroup(Group* group_ ) { group = group_; }
void Student::addmark(int mark) { marks.push_back(mark); }
double Student::Getaveragemark() {
  double average_mark = accumulate(marks.begin(), marks.end(), 0) / marks.size();
  return average_mark;
}
bool Student::isHeadOfGroup() { return group->getHead().id == id; }
int Student::Getid() { return id; }
std::string Student::Getname() { return fio; }