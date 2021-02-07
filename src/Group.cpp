// Copyright 2021 Pavlova D.
#include "Group.h"
#include <cstdlib>

void Group::addStudents(Student *student) { this->students.push_back(student); }

void Group::chooseHead() {
  if (!isEmpty()) {
    std::srand(time(nullptr));
    this->head = this->students[std::rand() % this->students.size()];
  }
}

double Group::getAverageMark() {
  double sum = 0;
  for (auto &student : this->students) {
    sum += student->getAverageMark();
  }

  return double(sum) / students.size();
}

int Group::containsStudent(Student student) {
  int iter = 0;
  for (auto students_ : students) {
    if (students_->id == student.id)
      return iter;
    iter++;
  }
}

void Group::removeStudent(int _id) {
  int indexst = 0;
  for (auto &student : students) {
    if (_id == student->getID()) {
      if (student == this->head) {
        this->head == nullptr;
        chooseHead();
      }
      students.erase(students.begin() + indexst);
    }
    indexst++;
  }
}

bool Group::isEmpty() { return this->students.empty(); }
