#include "Student.h"

#include <cstring>
#include <iostream>
#include <string>

Student::Student(const char* name) {
  fio = name;  // need be read from file
  id = -1;     // need be read from file
  group = "";
  isHead = false;
}

void Student::addmark(int value) { marks.push_back(value); }

void Student::addToGroup(const char* value) { group = value; }

float Student::getAveragemark() {
  double mean = 0.0;
  for (auto x : marks) {
    mean += x;
  }

  return mean / marks.size();
}

bool Student::isHeadOfGroup() { return isHead; }
