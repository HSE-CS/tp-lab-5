// Copyright 2021 Galex
#include "Student.h"
#include "Group.h"
#include <string>
#include <vector>

Student::Student(unsigned int id, std::string fio) {
  this->fio = fio;
  this->id = id;
}
void Student::add2group(Group *group2add) {
  if (!group2add->containsStudent(this->id)) {
    this->group = group2add;
    group2add->addStudent(this);
  }
}
void Student::removeFromGroup(Group *group2rem) {
  if (group2rem->containsStudent(this->id)) {
    this->group = nullptr;
    group2rem->removeStudent(this);
  }
}
void Student::addMark(int mark) {
  this->marks.push_back(mark);
}
double Student::getAverage() {
  double average = 0.0;
  for (int i = 0; i < this->marks.size(); ++i) {
    average += this->marks[i];
  }
  return (average/ this->marks.size());
}
bool Student::isHead() {
  return this->head;
}
void Student::setHead(bool isTrue){
  this->head = isTrue;
}
unsigned int Student::getId() {
  return this->id;
}

