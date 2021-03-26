// Copyright 2021 Shaidi
#include "Student.h"

Student::Student(std::string new_fio, unsigned int new_id) {
  fio = new_fio;
  id = new_id;
  group = nullptr;
  marks = std::vector<int>();
}

double Student::get_average_mark() const {
  int res = 0, sum = 0;
  for (int i = 0; i < marks.size(); i++) {
    sum += marks[i];
  }
  res = sum / marks.size();
  return res;
}

unsigned int Student::get_id() const {
    return id;
}

std::string Student::get_fio() const {
    return fio;
}

void Student::add_to_group(Group* new_group) {
    group = new_group;
}

void Student::add_mark(int new_mark) {
    marks.push_back(new_mark);
}
