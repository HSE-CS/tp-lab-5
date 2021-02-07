// Copyright 2021 Bulatov D.
#include "Student.h"

Student::Student(std::string fio, int id) {
  this->id = id;
  this->fio = fio;
  marks = std::vector<int>();
  group = nullptr;
}

void Student::addToGroup(Group* group) { this->group = group; }

void Student::addMark(int mark) { marks.push_back(mark); }

double Student::getAverageMark() {
  double sum = 0.0;
  for (int i = 0; i < marks.size(); i++) sum += marks[i];
  return sum / marks.size();
}

int Student::getId() { return id; }

std::string Student::getFio() { return fio; }

void Student::removeGroup() { group = nullptr; }

void Student::setMarks(std::vector<int> marks) { this->marks = marks; }

std::string Student::getGroupTitle() {
  if (group == nullptr) {
    return "-1";
  }
  return group->getTitle();
}
