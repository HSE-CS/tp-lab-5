// Copyright 2020 Konina Tatiana

#include "Student.h"
#include "Group.h"

Student::Student(unsigned int id, std::string fio,
                 std::vector <unsigned int> marks, std::string spec) {
  this->fio = fio;
  this->id = id;
  this->group = NULL;
  this->isHead = 0;
  this->marks = marks;
  this->spec = spec;
}

void Student::addMark(unsigned int mark) {
  marks.push_back(mark);
}
double Student::getAverage() {
  double result = 0;
  for (int i = 0; i < marks.size(); ++i) {
    result += marks[i];
  }
  result /= marks.size();
  return result;
}
bool Student::isHeadOfGroup() const {
  return this->isHead;
}

void Student::addToGroup(Group* group) {
  this->group = group;
}

std::string Student::getFio() const {
  return this->fio;
}
unsigned int Student::getId() const {
  return this->id;
}
std::string Student::getSpec() const  {
  return this->spec;
}
void Student::initHead() {
  this->isHead = true;
}
std::vector<unsigned int> Student::getMarks()const {
  return this->marks;
}

