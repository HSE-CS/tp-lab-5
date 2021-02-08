// Copyright 2021 Ryzhova
#include "Student.h"
#include "Group.h"

Student::Student(int id, std::string fio, Group* group) {
  this->id = id;
  this->fio = fio;
  this->group = group;
}

double Student::get_average_mark() {
  int res{0};
  for (int tmp: marks) {
    res += tmp;
  }
  return marks.empty() ? 0 : res / marks.size();
}

bool Student::is_head_of_group() {
  return group != nullptr && group->head == this;
}

int Student::get_id() {
  return id;
}

std::string Student::get_fio() {
  return fio;
}

void Student::add_mark(int mark) {
  marks.push_back(mark);
}
