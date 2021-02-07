// Copyright 2021 Egor Buzanov

#include "../include/Group.h"

Group::Group(std::string _title, std::string _spec) {
  title = _title;
  spec = _spec;
  head = nullptr;
}

void Group::AddStudent(Student *_student) { students.push_back(_student); }

void Group::chooseHead() {
  if (!isEmpty()) {
    std::random_device rd;
    std::mt19937 mersenne(rd());
    head = students[mersenne() % students.size()];
  } else {
    head == nullptr;
  }
}

void Group::removeStudent(Student *_student) {
  if (containsStudent(_student->getId())) {
    for (size_t i = 0; i < students.size(); i++) {
      if (students[i] == _student) {
        students[i] = students.back();
        students.pop_back();
      }
    }
    if (_student == head) {
      chooseHead();
    }
  }
}

double Group::getAverageMark() {
  double average_mark = 0.0;
  for (const auto student : students) {
    average_mark += student->getAverageMark();
  }
  average_mark /= students.size();
  return average_mark;
}

Student *Group::getStudent(int _id) {
  for (const auto &student : students) {
    if (student->getId() == _id) {
      return student;
    }
  }
  return nullptr;
}

bool Group::containsStudent(int _id) {
  for (const auto student : students) {
    if (student->getId() == _id) {
      return true;
    }
  }
  return false;
}

bool Group::isEmpty() { return !(students.size()); }

Student *Group::getHead() { return head; }
