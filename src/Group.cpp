// Copyright 2021 ArinaMonicheva

#include "Group.h"

Group::Group(std::string newTitle = "") {
  title = newTitle;
  head = NULL;
}

void Group::addStudent(Student& newStudent) {
  if (containsStudent(newStudent.id) == -1) {
    students.push_back(&newStudent);
    newStudent.group = this;
  }
}

void Group::chooseHead(Student* candidate) {
  if (containsStudent(candidate->id) > -1) {
    head = candidate;
    candidate->isHead = true;
  }
}

Student& Group::getStudent(unsigned id) const {
  for (auto i : students) {
    if (i->id == id) {
      return *i;
    }
  }
  throw "No such student";
}

Student& Group::getStudent(std::string fio) const {
  for (auto i : students) {
    if (i->fio == fio) {
      return *i;
    }
  }
  throw "No such student";
}

int Group::containsStudent(unsigned id) {
  int j = 0;
  for (auto i : students) {
    if (i->id == id) {
      return j;
    }
    j++;
  }
  return -1;
}

int Group::containsStudent(std::string fio) {
  int j = 0;
  for (auto i : students) {
    if (i->fio == fio) {
      return j;
    }
    j++;
  }
  return -1;
}

double Group::getAverageMark() {
  double averageMark = 0.0;
  int j = 0;

  for (auto i : students) {
    averageMark += i->getAverageMark();
    j++;
  }

  return averageMark / j;
}

void Group::removeStudent(Student& removalOne) {
  int index = containsStudent(removalOne.id);
  if (index > -1) {
    if (removalOne.isHeadOfGroup()) {
      removalOne.isHead = false;
      head = NULL;
    }
    students.erase(students.begin() + index);
    removalOne.group = NULL;
  }
}
