// Copyright 2021 Galex
#include <string>
#include "../include/Student.h"
#include "../include/Group.h"

Student::Student(unsigned int id, std::string fio) {
  this->fio = fio;
  this->id = id;
  this->head = false;
}
void Student::add2group(Group *group2add) {
  if (!group2add->containsStudent(this->id)) {
    this->group = group2add;
    group2add->addStudent(this);
  }
}
void Student::remove() {
  this->group->removeStudent(this);
  delete this;
}
void Student::addMark(int mark) {
  this->marks.push_back(mark);
}
double Student::getAverage() {
  if (!this->isAnyMarks()) {
    return 0.0;
  }
  double average = 0.0;
  for (int i = 0; i < this->marks.size(); ++i) {
    average += this->marks[i];
  }
  return (average / this->marks.size());
}
bool Student::isHead() {
  return this->head;
}
void Student::setHead(bool isTrue) {
  this->head = isTrue;
}
unsigned int Student::getId() {
  return this->id;
}
bool Student::isAnyMarks() {
  if (this->marks.empty()) {
    return false;
  }
  return true;
}
std::string Student::getName() {
  return this->fio;
}
std::string Student::getMarks2String() {
  std::string marks = "";
  for (int i = 0; i < this->marks.size(); ++i) {
    marks.append(" ");
    marks.append(std::to_string(this->marks[i]));
  }
  return marks;
}

