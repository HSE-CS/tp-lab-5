// Copyright 2021 Andrey Bakurskii

#include "Group.h"

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

Student* Group::getStudent_byID(int id) {
  for (size_t i = 0; i < this->students.size(); i++) {
    if (this->students[i]->id == id) {
      return this->students[i];
    }
  }
  return nullptr;
}

Student* Group::getStudent_byFIO(std::string fio) {
  for (size_t i = 0; i < this->students.size(); i++) {
    if (this->students[i]->fio == fio) {
      return this->students[i];
    }
  }
  return nullptr;
}

float Group::getAveragemark() {
  float sum = 0.0;
  size_t size = this->students.size();

  for (size_t i = 0; i < size; i++) {
    sum += this->students[i]->getAveragemark();
  }
  if (size == 0) {
    return 0.0;
  }
  return sum / size;
}

Student* Group::getHead() { return this->head; }

bool Group::containsStudent(Student* student) {
  for (size_t i = 0; i < this->students.size(); i++) {
    if (this->students[i] == student) {
      return true;
    }
  }
  return false;
}

bool Group::isEmpty() { return this->students.size() == 0; }

void Group::printGroup(bool with_statistic) {
  std::cout << this->title << " " << this->spec << std::endl;
  if (with_statistic) {
    std::cout << "Group's averagemark: " << this->getAveragemark() << std::endl;
    for (size_t i = 0; i < this->students.size(); i++) {
      std::cout << this->students[i]->getId() << " "
                << this->students[i]->getFIO() << " "
                << this->students[i]->getAveragemark() << std::endl;
    }
  } else {
    for (size_t i = 0; i < this->students.size(); i++) {
      std::cout << this->students[i]->getId() << " "
                << this->students[i]->getFIO() << std::endl;
    }
  }
}

std::string Group::getGroupAsString() {
  std::string g;
  g += (this->title + " " + this->spec + "\n");
  for (size_t i = 0; i < this->students.size(); i++) {
    g += (std::to_string(this->students[i]->getId()) + " "
        + this->students[i]->getFIO() + "\n");
  }
  return g;
}

std::string Group::getTittle() { return this->title; }

std::string Group::getSpec() { return this->spec; }

void Group::addStudent(Student* new_student) {
  this->students.push_back(new_student);
  new_student->addToGroup(this);
}

void Group::chooseHead() {
  int size = this->students.size();
  if (!size) {
    return;
  }
  int indexHead = std::rand() % size;
  this->head = this->students[indexHead];
}

void Group::removeStudent(Student* student) {
  for (size_t i = 0; i < this->students.size(); i++) {
    if (this->students[i] == student) {
      this->students[i]->addToGroup(nullptr);
      this->students.erase(this->students.begin() + i);
      return;
    }
  }
}
