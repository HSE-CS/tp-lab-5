#include "Student.h"
#include <cstring>
#include <iostream>
#include <string>

Student::Student(int _id, std::string name) {
  fio = name;
  id = _id;
  group = NULL;
  isHead = false;
}

void Student::addmark(int value) { marks.push_back(value); }

void Student::addToGroup(Group * value) { group = value; }

float Student::getAveragemark() {
  double mean = 0.0;
  for (auto x : marks) {
    mean += x;
  }

  return mean / marks.size();
}

bool Student::isHeadOfGroup() { return isHead; }

int Student::getId() { return id; }

const std::string &Student::getName() const {
    return fio;
}
