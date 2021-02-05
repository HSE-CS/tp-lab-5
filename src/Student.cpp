// Copyright 2020 Osmanov Islam

#include <string>
#include "Student.h"


Student::Student(int curr_id, std::string fullName) {
  this->id = curr_id;
  this->fio = move(fullName);
  this->group = nullptr;
}

void Student::addMark(int mark) {
  this->marks.push_back(mark);
}

void Student::addToGroup(Group* group) {
  this->group = group;
}

bool Student::isHeadOfGroup() {
  if (this->group != nullptr) {
    if (this->group->getHead() == this) {
      return true;
    } else {
            return false;
        }
  }
    return false;
}

int Student::getId() const {
    return this->id;
}

double Student::getAveragemark() {
  double average = 0.0;
  double sum = 0.0;
  if (this->marks.size() != 0) {
    for (int currentMark : this->marks) {
      sum = sum + currentMark;
    }
  } else {
    return 0.0;
  }
  average = sum / this->marks.size();
  return average;
}

std::string Student::getFIO() {
    return this->fio;
}
