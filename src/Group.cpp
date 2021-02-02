// Copyright 2021 Galex
#include "Group.h"
#include <string>

Group::Group(std::string name, std::string spec) {
  this->name = name;
  this->spec = spec;
}
void Group::addStudent(Student *student) {
  this->students.push_back(student);
}
void Group::removeStudent(Student *student) {
  for (int i = 0; i < this->students.size(); i++) {
    if (students[i]->getId() == student->getId()) {
      if (student->getId() == this->head->getId()) {
        student->setHead(false);
        chooseHead(nullptr);
      }
      students.erase(students.begin() + i);
      return;
    }
  }
}
void Group::chooseHead(Student *student) {
  this->head = student;
  student->setHead(true);
}
double Group::getAverage() {
  double average = 0.0;
  for (int i = 0; i < this->students.size(); ++i) {
    average += students[i]->getAverage();
  }
  return (average / this->students.size());
}
Student *Group::getStudent(unsigned int id) {
  for (int i = 0; i < this->students.size(); i++) {
    if (students[i]->getId() == id) {
      return students[i];
    }
  }
}
bool Group::containsStudent(unsigned int id) {
  for (int i = 0; i < this->students.size(); i++) {
    if (students[i]->getId() == id) {
      return true;
    }
    return false;
  }
}
bool Group::isEmpty() {
  if (this->students.empty()) {
    return true;
  }
  return false;
}
bool Group::isHeadChoosen() {
  if (this->head != nullptr) {
    return true;
  }
  return false;
}