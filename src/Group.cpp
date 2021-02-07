// Copyright 2021 Artem Danyaev
#include "Group.h"

Group::Group(const std::string &t, const std::string &s) : title(t), spec(s) {}

void Group::addStudent(Student *student) {
  student->addToGroup(this);
  students.push_back(student);
}

void Group::chooseHead(unsigned int id) {
  for (Student *st : students) {
    if (st->id == id) {
      head = st;
      break;
    }
  }
}

std::string Group::getTitle() { return title; }
std::string Group::getSpec() { return spec; }

Student *Group::getStudentByFio(const std::string& f) {
  for (Student *st : students) {
    if (st->fio == f) {
      return st;
    }
  }
  return nullptr;
}

void Group::removeStudent(unsigned int id) {
  for (int i = 0; i < students.size(); i++) {
    if (students[i]->id == id) {
      students.erase(students.begin() + i);
      break;
    }
  }
  if (head && head->id == id) {
    head = nullptr;
  }
}

bool Group::isEmpty() { return students.empty(); }

float Group::getAverageMark() {
  if (students.empty()) {
    return 0;
  }
  float c = 0;
  for (Student *st : students) {
    c += st->getAverageMark();
  }
  return c / students.size();
}

Student *Group::getStudentById(unsigned int id) {
  Student *res = nullptr;
  for (Student *st : students) {
    if (st->id == id) {
      res = st;
      break;
    }
  }
  return res;
}

bool Group::containsStudentById(unsigned int id) {
  for (Student *st : students) {
    if (st->id == id) {
      return true;
    }
  }
  return false;
}

bool Group::containsStudentByFio(std::string f) {
  for (Student *st : students) {
    if (st->fio == f) {
      return true;
    }
  }
  return false;
}
