// Copyright 2021 Dev-will-work
#include <random>
#include "Group.h"
#include "Student.h"

Group::Group(std::string name, std::string spec) {
  this->title = name;
  this->spec = spec;
}

Group::~Group() {
  for (size_t i = 0; i < this->students.size(); i++) {
    delete students[i];
  }
}

size_t Group::size() { return this->students.size();}

Student* Group::operator[](int index) {
  if (index < 0 || index >= this->students.size()) return nullptr;
  else
    return this->students[index];
}  // get by index

int Group::addStudent(Student* st) {
  if (st) this->students.push_back(st);
  return 0;
}

void Group::chooseHead() {
  std::random_device rd;
  std::mt19937 mersenne(rd());
  int head_number = mersenne() % this->students.size();
  this->head = this->students[head_number];
}

float Group::getAverageMark() {
  float average = 0;
  for (size_t i = 0; i < this->students.size(); i++) {
    average += this->students[i]->getAveragemark();
  }
  if (this->students.size() != 0) average /= this->students.size();
  return average;
}

Student* Group::getStudent(std::string name) {
  for (size_t i = 0; i < this->students.size(); i++) {
    if (this->students[i]->getName() == name) {
      return this->students[i];
    }
  }
  return nullptr;
}

Student* Group::getStudent(uint64_t id) {
  for (size_t i = 0; i < this->students.size(); i++) {
    if (this->students[i]->getId() == id) {
      return this->students[i];
    }
  }
  return nullptr;
}

std::string Group::getName() {
  return this->title;
}

std::string Group::getSpec() {
  return this->spec;
}

bool Group::containsStudent(Student* st) {
  if (st) {
    for (size_t i = 0; i < this->students.size(); i++) {
      if (*(this->students[i]) == *st) {
        return true;
      }
    }
  }
  return false;
}

bool Group::containsStudent(std::string name) {
  for (size_t i = 0; i < this->students.size(); i++) {
    if (this->students[i]->getName() == name) {
      return true;
    }
  }
  return false;
}
bool Group::containsStudent(uint64_t id) {
  for (size_t i = 0; i < this->students.size(); i++) {
    if (this->students[i]->getId() == id) {
      return true;
    }
  }
  return false;
}

Student* Group::getHead() {
  return this->head;
}

int Group::removeStudent(Student* st) {
  if (st) {
    for (size_t i = 0; i < this->students.size(); i++) {
      if (*(this->students[i]) == *st) {
        if (this->students[i]->isHeadOfGroup()) this->head = nullptr;
        delete this->students[i];
        this->students.erase(this->students.begin() + i);
        if (!this->isEmpty()) this->chooseHead();
        return 0;
      }
    }
  }
  return -1;
}

int Group::removeStudent(std::string name) {
  for (size_t i = 0; i < this->students.size(); i++) {
    if (this->students[i]->getName() == name) {
      if (this->students[i]->isHeadOfGroup()) this->head = nullptr;
      delete this->students[i];
      this->students.erase(this->students.begin() + i);
      if (!this->isEmpty()) this->chooseHead();
      return 0;
    }
  }
  return -1;
}
int Group::removeStudent(uint64_t id) {
  if (id >= 0) {
    for (size_t i = 0; i < this->students.size(); i++) {
      if (this->students[i]->getId() == id) {
        if (this->students[i]->isHeadOfGroup()) this->head = nullptr;
        delete this->students[i];
        this->students.erase(this->students.begin() + i);
        if (!this->isEmpty()) this->chooseHead();
        return 0;
      }
    }
  }
  return -1;
}

bool Group::isEmpty() { return this->students.size() == 0; }
