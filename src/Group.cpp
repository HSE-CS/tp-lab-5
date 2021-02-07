// Copyright 2021 Galex
#include <string>
#include "../include/Group.h"

Group::Group(std::string name, std::string spec) {
  this->name = name;
  this->spec = spec;
  this->students = {};
  this->head = nullptr;
}
void Group::addStudent(Student *student) {
  this->students.push_back(student);
  if (!this->isHeadChoosen()) {
    this->chooseHead(student);
  }
}
void Group::removeStudent(Student *student) {
  for (int i = 0; i < this->students.size(); i++) {
    if (students[i]->getId() == student->getId()) {
      if (student->isHead()) {
        students.erase(students.begin() + i);
        chooseHead(this->students[std::rand() % this->students.size()]);
        return;
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
int Group::getNumOfStudents() {
  return this->students.size();
}
Student *Group::getStudentByIndex(int i) {
  return students[i];
}
std::string Group::getName() {
  return this->name;
}
Student *Group::getHead() {
  return this->head;
}
