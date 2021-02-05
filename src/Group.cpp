// Copyright 2021 Drobot E.D.

#include "Group.h"

Group::Group(std::string title, std::string spec) {
  this->title = title;
  this->spec = spec;
}

void Group::add_student(Student *student) {
  students.push_back(student);
  student->group = this;
}

void Group::choice_head() {
  if (students.size() != 0) {
    int number = std::rand() % students.size();
    head = students[number];
  }
}

void Group::remove_student(Student* student) {
  for (int i = 0; i < students.size(); i++) {
    if (students[i]->get_fio() == student->get_fio()) {
      for (int j = i + 1; j < students.size(); j++) {
        students[j - 1] = students[j];
      }
      students.pop_back();
      break;
    }
  }
}

bool Group::find_student(int id) {
  for (int i = 0; i < students.size(); i++) {
    if (students[i]->get_id() == id) {
      return true;
    }
  }
  return false;
}

bool Group::find_student(std::string fio) {
  for (int i = 0; i < students.size(); i++) {
    if (students[i]->get_fio() == fio) {
      return true;
    }
  }
  return false;
}

double Group::avarage_mark() {
  double sum = 0;
  int num = 0;

  for (auto* student : students) {
    sum += student->average_mark();
    num++;
  }
  if (sum == 0) {
    return 0;  
  } else {
    return sum / num;
  }
}

std::string Group::get_title() {
    return title;
}

std::string Group::get_spec() {
    return spec;
}