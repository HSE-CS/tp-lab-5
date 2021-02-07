// Copyright 2021 alexgiving

#include "Group.h"

#include <numeric>
#include <utility>

Group::Group(std::string _title, std::string _spec) {
  this->title = std::move(_title);
  this->spec = std::move(_spec);
}

void Group::choose_headman() {
  if (!students.empty()) {
    headman = students[std::rand() % students.size()];
  }
}

void Group::add_student(Student* _student) {
  students.push_back(_student);
  _student->group = this;
}

void Group::remove_student(Student* _student) {
  for (size_t index = 0; index < students.size(); ++index) {
    if (_student->id == students[index]->get_id()) {
      students.erase(students.begin() + index);
      break;
    }
  }
}

bool Group::find_student(int _id) {
  for (auto* student : students) {
    if (student->id == _id)
      return true;
  }
  return false;
}

bool Group::find_student(const std::string& _name) {
  for (auto* student : students)
    if (student->name == _name) return true;
  return false;
}

double Group::average_mark() {
  double sum = 0;
  for (auto* student : students)
    sum += student->average_mark();
  if (!students.empty())
    return sum/students.size();
  return 0;
}

std::string Group::get_title() {
  return title;
}
std::string Group::get_spec() {
  return spec;
}
