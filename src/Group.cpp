// Copyright 2021 Schenikova

#include "Group.h"

void Group::addStudent(Student* student) {
  this->students.push_back(student);
  student->addToGroup(this);
}

void Group::chooseHead() {
  std::srand(time(0));
  if (students.size()) {
    head = students[std::rand() % students.size()];
  }
}

void Group::removeStudent(Student* student) {
  for (int i = 0; i < students.size(); i++) {
    if (students[i] == student)
      students.erase(students.begin() + i);
  }
}

Group::Group(std::string title, std::string spec) {
  this->title = title;
  this->spec = spec;
  this->head = nullptr;
}

std::string Group::getTitle() {
  return this->title;
}

std::string Group::getSpec() {
  return this->spec;
}

Student* Group::getStudentById(int id) {
  for (auto s : students) {
    if (s ->id == id) {
      return s;
    }
  }
  return nullptr;
}

Student* Group::getStudentByFio(std::string fio) {
  for (auto s : students) {
    if (s->fio == fio) {
      return s;
    }
  }
  return nullptr;
}

float Group::getAveragemark() {
  float average = 0;
  for (auto student : students) {
    average += student->getAveragemark();
  }
  if (students.size())
    return average / students.size();
}

std::vector<Student *> Group::containsStudent() {
  return this->students;
}

bool Group::isEmpty() {
  return students.size() ? false : true;
}
