// Copyright 2021 Andrey Bakurskii

#include "Student.h"

Student::Student() {
  this->fio = "";
  this->id = 0;
  this->group = nullptr;
}

Student::Student(int new_id, std::string new_fio) {
  this->fio = new_fio;
  this->id = new_id;
}

Student::Student(Student* new_student) {
  this->id = new_student->id;
  this->fio = new_student->fio;
  this->group = new_student->group;
  size_t size = new_student->marks.size();
  for (size_t i = 0; i < size; i++) {
    this->marks[i] = new_student->marks[i];
  }
}

float Student::getAveragemark() {
  size_t n = this->marks.size();
  float average = 0.0f;
  for (size_t i = 0; i < n; i++) {
    average += static_cast<float>(marks[i]);
  }

  if (this->marks.size() == 0) {
    return 0.0;
  }
  return average / n;
}

bool Student::isHeadOfGroup() {
  return (this->group != nullptr && this->group->getHead() == this);
}

std::string Student::getFIO() { return this->fio; }

int Student::getId() { return this->id; }

void Student::addToGroup(Group* group) { this->group = group; }

void Student::addmark(int mark) { this->marks.push_back(mark); }
