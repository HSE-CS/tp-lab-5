// Copyright 2020 Dumarevskaya
#include "Group.h"
#include <algorithm>

void Group::addStudent(Student* student) {
  students.push_back(student);
  student->addToGroup(this);
}

void Group::chooseHead(Student* head_name) {
  head = head_name;
}

double Group::getAveragemark() {
  if (students.size() == 0)
    return 0;
  double average = 0;
  for (auto i : students) {
    average += i->getAveragemark();
  }
  return average / students.size();
}

Student* Group::getStudent(std::string student) {
  for (auto i : students) {
    if (i->id == student || i->fio == student) {
      return i;
    }
  }
  std::cout << "there is no such student in the " << title
    << "group" << std::endl;
  return new Student("error", "error");
}

bool Group::containsStudent(std::string student) {
  for (auto i : students) {
    if (i->id == student || i->fio == student) {
      return true;
    }
  }
  return false;
}

void Group::removeStudent(Student* student) {
  auto index = std::find(students.begin(), students.end(), student);
  students.erase(index);
}

bool Group::isEmpty() {
  return students.empty();
}
