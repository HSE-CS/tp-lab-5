#include "Group.h"

// Copyright 2020 Polina Lukicheva

Group::Group() {
  this->title = "";
  this->spec = "";
  this->head = nullptr;
}

Group::Group(const std::string title) {
  this->title = title;
  this->spec = "";
  this->head = nullptr;
}

Group::Group(const std::string title, const std::string spec) {
  this->title = title;
  this->spec = spec;
  this->students = std::vector<Student*>();
  this->head = nullptr;
}

Group::~Group() {
}

void Group::addStudent(Student* student) {
  students.push_back(student);
}

void Group::chooseHead() {
  if (!head) {
    head = students[std::rand() % students.size()];
  }
}


void Group::removeStudent(Student* student) {
  for (int i = 0; i < students.size(); ++i)
    if (students[i] == student) {
      students.erase(students.begin() + i);
      break;
    }
  if (student == head)
    chooseHead();
}

bool Group::isEmpty() {
  return !(students.size());
}

Student* Group::getStudent(int id) {
  for (auto& student : students)
    if (student->getId() == id)
      return student;
  return nullptr;
}

Student* Group::getHead() {
  return head;
}

bool Group::containsStudent(Student* student) {
  for (auto& stud : students)
    if (stud == student)
      return true;
  return false;
}

float Group::getAverageMark() {
  float averMark = 0.0;
  for (auto student : students)
    averMark += student->averageMark();
  return averMark / students.size();
}

