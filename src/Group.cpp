// Copyright 2021 Ryzhova
#include "Group.h"
#include "Student.h"
#include <algorithm>

Group::Group(std::string title, std::string spec) {
  this->title = title;
  this->spec = spec;
  head = nullptr;
}

double Group::get_avarage_mark() {
  int res{0};
  for (auto tmp: students){
    res += tmp->get_average_mark();
  }
  return is_empty() ? 0 : res / students.size();
}

void Group::remove_student(Student *student) {
  if (contains_student(student->id))
    students.erase(std::remove(students.begin(), students.end(), student), students.end());
}

bool Group::is_empty() {
  return students.empty();
}

void Group::choose_head() {
  if (!is_empty())
    head = students[std::rand() % students.size()];
}

bool Group::contains_student(int id) {
  for (auto tmp: students) {
    if (tmp->get_id() == id)
      return true;
  }
  return false;
}

void Group::add_student(Student* student) {
  students.push_back(student);
  student->group = this;
}

std::string Group::get_title() {
  return title;
}

std::string Group::get_spec() {
  return spec;
}

Student* Group::get_student(int id) {
  for (auto tmp: students) {
    if (tmp->get_id() == id)
      return tmp;
  }
  return nullptr;
}
