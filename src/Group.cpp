// Copyright 2020 GHA Test Team
#include "Group.h"


void Group::addStudent(Student* student) {
  this->students.push_back(student);
}

void Group::chooseHead(bool random) {
  unsigned number_of_students = this->students.size();
  if (number_of_students) {
    unsigned head_i;
    if (random)
      head_i = std::rand() % number_of_students;
    else
      head_i = 0;
    this->head = this->students.at(head_i);
  }
}

std::string Group::getTitle() const {
  return this->title;
}

void Group::removeStudentById(int id) {
  unsigned number_of_students = this->students.size();
  for (unsigned i = 0; i < number_of_students; i++) {
    if (this->students.at(i)->getId() == id) {
      this->students.erase(this->students.begin() + i);
      break;
    }
  }
}

void Group::removeStudentByFio(std::string fio) {
  unsigned number_of_students = this->students.size();
  for (unsigned i = 0; i < number_of_students; i++) {
    if (this->students.at(i)->getFio() == fio) {
      this->students.erase(this->students.begin() + i);
      break;
    }
  }
}

Group::Group() {
  this->title = "";
  this->spec = "";
  this->head = nullptr;
}

Group::Group(std::string title) {
  this->title = title;
  this->spec = "";
  this->head = nullptr;
}

Group::Group(std::string title, std::string spec) {
  this->title = title;
  this->spec = spec;
  this->head = nullptr;
}

Student* Group::getHead() const {
  return this->head;
}

int Group::getAvarageMark() const {
  unsigned size = this->students.size();
  float sum_of_marks = 0.0f;
  for (unsigned i = 0; i < size; i++) {
    sum_of_marks += this->students.at(i)->getAverageMark();
  }
  return sum_of_marks / size;
}

Student* Group::getStudentById(int id) {
  unsigned size = this->students.size();
  if (!size) 
    return nullptr;
  else {
    for (unsigned i = 0; i < size; i++) {
      if (this->students.at(i)->getId() == id) {
        return this->students.at(i);
        break;
      }
    }
  }
  return nullptr;
}

Student* Group::getStudentByFio(std::string fio) {
  unsigned size = this->students.size();
  if (!size) 
    return nullptr;
  else {
    for (unsigned i = 0; i < size; i++) {
      if (this->students.at(i)->getFio() == fio) {
        return this->students.at(i);
        break;
      }
    }
  }
  return nullptr;
}

bool Group::containsStudent(Student* student) const {
  unsigned size = this->students.size();
  for (unsigned i = 0; i < size; i++) {
    if (this->students.at(i) == student)
      return true;
  }
  return false;
}

bool Group::isEmpty() const {
  return !static_cast<bool>(this->students.size());
}
