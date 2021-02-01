// Copyright 2020 GHA Test Team
#include "Student.h"


void Student::addToGroup(Group* group) {
  this->group = group;
}

void Student::addMark(int mark) {
  this->marks.push_back(mark);
}

Student::Student() {
  this->id = 0;
  this->fio = "";
  this->group = nullptr;
}

Student::Student(int id, std::string fio) {
  this->id = id;
  this->fio = fio;
}

void Student::setGroup(Group* group) {
  this->group = group;
}

Student::Student(Student* other_student) {
  this->id = other_student->id;
  this->fio = other_student->fio;
  this->group = other_student->group;
  unsigned size = other_student->marks.size();
  for (unsigned i = 0; i < size; i++) {
    this->marks.push_back(other_student->marks.at(i));
  }
}

float Student::getAverageMark() const {
  unsigned size = this->marks.size();
  float sum_of_marks = 0.0f;
  for (unsigned i = 0; i < size; i++) {
    sum_of_marks += this->marks.at(i);
  }
  return sum_of_marks / size;
}

void Student::printMarks() {
  unsigned number_of_marks = this->marks.size();
  for (unsigned i = 0; i < number_of_marks; i++)
    std::cout << this->marks.at(i) << " ";
}

bool Student::isHeadOfGroup() const {
  return this->group != nullptr && this->group->getHead() == this;
}

int Student::getId() const {
  return this->id;
}

std::string Student::getFio() const {
  return this->fio;
}
