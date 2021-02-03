// Copyright 2021 Schenikova

#include "Student.h"

void Student::addToGroup(Group* group) {
  this->group = group;
}

void Student::addMark(int mark) {
  this->marks.push_back(mark);
}

Student::Student(unsigned int id, std::string fio) {
  this->id = id;
  this->fio = fio;
  this->group = nullptr;
}

Group* Student::getGroup() {
  return group;
}

bool Student::isHeadOfGroup() {
  if (this->group->head ==this)
    return true;
  return false;
}

float Student::getAveragemark(){
  float average = 0;
  for (auto mark: marks) {
    average += mark;
  }
  if (marks.size())
    return average / marks.size();
}

int Student::getId(){
  return this->id;
}

std::string Student::getfio() {
  return this->fio;
}
