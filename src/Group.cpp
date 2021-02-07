// Copyright 2021 Bulatov D.
#include "Group.h"
#include <iostream>

Group::Group(std::string title, std::string spec) {
  this->title = title;
  this->spec = spec;
}

void Group::addStudent(const Student& student) {
  students.push_back(student);
  students[students.size() - 1].addToGroup(this);
}

void Group::chooseHead() {
  int num = std::rand() % (students.size());
  this->head = &(students[num]);
}

Student& Group::getStudent(int id) {
  for (int i = 0; i < students.size(); i++) {
    if (students[i].getId() == id) {
      return students[i];
    }
  }
}

Student& Group::getStudent(std::string fio) {
  for (int i = 0; i < students.size(); i++) {
    if (students[i].getFio() == fio) {
      return students[i];
    }
  }
}

double Group::getAverageMark() {
  double sum = 0.0;
  for (int i = 0; i < students.size(); i++) {
    sum += students[i].getAverageMark();
  }
  return sum / students.size();
}

void Group::removeStudent(int id) {
  auto iter = students.begin();
  for (int i = 0; i < students.size(); i++) {
    if (students[i].getId() == id) {
      students.erase(iter + i);
      students[i].removeGroup();
      return;
    }
  }
}

std::string Group::getTitle() { return title; }

std::string Group::getSpec() { return spec; }

Student* Group::getHead() { return head; }

std::vector<Student> Group::getStudents() { return students; }
