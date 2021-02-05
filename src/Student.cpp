// Copyright 2021 Drobot E.D.

#include "Student.h"

Student::Student(int id, std::string fio) {
  this->id = id;
  this->fio = fio;
  this->marks = std::vector<int>();
  this->group = nullptr;
}

void Student::add_to_group(Group* group) {
  this->group = group;
}

void Student::add_mark(int mark) {
    if (mark >= 0 && mark <= 10) {
        marks.push_back(mark);
    }
}

double Student::average_mark() {
  int sum = 0;
  int num = 0;
    for (int i = 0; i < marks.size(); i++) {
          sum += marks[i];
          num++;
     }
        if (sum == 0) {
          return 0;
        } else {
          return sum / num;
        }
}

int Student::get_id() {
    return id;
}

std::string Student::get_fio() {
    return fio;
}
