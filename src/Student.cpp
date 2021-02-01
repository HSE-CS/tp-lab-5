// Copyright 2021 VadMack

#include "Student.h"
#include "Group.h"

#include <utility>

void enroll();
void addMark();
double calculateAverageGrade();

Student::Student(std::string id, std::string fio)
    : id(std::move(id)), fio(std::move(fio)) {}

void Student::addToGroup(Group *group) {
  this->group = group;
  if (group->getStudent(this->id) == nullptr) {
    group->addStudent(this);
  }
}

Group *Student::getGroup() const {
  return group;
}

std::string Student::getId() const {
  return id;
}
const std::string &Student::getFio() const {
  return fio;
}
void Student::setId(std::string id) {
  Student::id = id;
}
void Student::setFio(const std::string &fio) {
  Student::fio = fio;
}

void Student::addMark(int mark) {
  this->marks.reserve(this->marks.size() + 1);
  this->marks.push_back(mark);
}

double Student::calculateAverageMark() {
  double sum = 0;
  int counter = 0;
  for (int i = 0; i < this->marks.size(); ++i) {
    sum += this->marks.at(i);
    counter++;
  }
  return sum/counter;
}

void Student::setGroup(Group *group) {
  Student::group = group;
}
const std::vector<int> &Student::getMarks() const {
  return marks;
}
Student::~Student() = default;



