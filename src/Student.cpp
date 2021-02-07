// Copyright 2021 alexgiving

#include "Student.h"

#include <utility>
#include <numeric>

Student::Student(int _id, std::string _name) {
  this->id = _id;
  this->name = std::move(_name);
  this->group = nullptr;
  this->marks = std::vector<int>();
}

void Student::add_to_group(Group* _group) {
  this->group = _group;
}

void Student::add_mark(int _mark) {
  marks.push_back(_mark % 11);  // Все оценки к виду 0 - 10
}

double Student::average_mark() {
  double sum = std::accumulate(marks.begin(), marks.end(), 0);
  if (!marks.empty())
    return sum/marks.size();
  return 0;
}


int Student::get_id() const {
  return id;
}
std::string Student::get_name() {
  return name;
}