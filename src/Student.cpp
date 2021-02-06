// Copyright 2021 Dev-will-work
#include <ctime>
#include <iostream>
#include "../include/Student.h"
#include "../include/Group.h"

Student::Student(std::string& fio, uint64_t id) {
  this->fio = fio;
  this->id = id;
}

int Student::operator[](int index) {
  if (index < 0 || index >= this->marks.size()) return 0;
  else
    return this->marks[index];
}  // get by index

bool Student::operator==(const Student& arg) {
  return (this->id == arg.id) && (this->fio == arg.fio);
}

bool Student::operator!=(const Student& arg) {
  return (this->id != arg.id) || (this->fio != arg.fio);
}

std::ostream& operator<<(std::ostream& out, Student& arg) {
  out << "Student: " << arg.fio << '\n' << "Student id: " << arg.id;
  out << '\n' << "Marks: ";
  for (size_t i = 0; i < arg.marks.size(); i++) {
    out << arg.marks[i] << ' ';
  }
  out << '\n';
  return out;
}  // output

int Student::addToGroup(Group* group) {
  if (group) this->group = group;
  return 0;
}

void Student::addmark(int mark) {
  if (mark < 1 || mark > 5) return;
  else
    this->marks.push_back(mark);
}

float Student::getAveragemark() {
  float average = 0;
  for (size_t i = 0; i < this->marks.size(); i++) {
    average += marks[i];
  }
  if (this->marks.size() > 0)average /= this->marks.size();
  return average;
}

bool Student::isHeadOfGroup() { return *(this->group->getHead()) == *this;}

uint64_t Student::getId() {
  return this->id;
}

std::string Student::getName() {
  return this->fio;
}

size_t Student::size() { return this->marks.size();}
