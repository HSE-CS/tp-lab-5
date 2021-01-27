// Copyright 2020 Stanislav Stoianov

#include <algorithm>
#include <utility>
#include "../include/Group.h"

Group::Group(std::string t) {
  this->title = std::move(t);
}

Group::Group(std::string t, std::string s) {
  this->title = std::move(t);
  this->spec = std::move(s);
}

void Group::addStudent(Student *student) {
  student->addToGroup(this);
  this->students.push_back(student);
}

void Group::chooseHead(Student *student) {
  this->head = student;
}

Student *Group::containsStudent(int id) {
  for (Student *student : this->students) {
    if (student->getId() == id) return student;
  }
  throw std::invalid_argument("Student does not exist");
}

Student *Group::containsStudent(const std::string &fio) {
  for (Student *student : this->students) {
    if (student->getFullname() == fio) return student;
  }
  throw std::invalid_argument("Student does not exist");
}

double Group::getAverageMark() {
  double accum = 0.0;
  for (Student *student : this->students) {
    accum += student->getAverageMark();
  }
  return this->students.empty() ? 0.0 : accum / this->students.size();
}

void Group::removeStudent(Student *student) {
  if (this->head == student) this->head = nullptr;
  this->students.erase(
      std::remove(this->students.begin(), this->students.end(), student),
      this->students.end());
  student->addToGroup(nullptr);
}

const std::string &Group::getTitle() const {
  return title;
}

const std::string &Group::getSpec() const {
  return spec;
}

Student *Group::getHead() const {
  return head;
}

std::vector<Student *> &Group::getStudents() {
  return students;
}
