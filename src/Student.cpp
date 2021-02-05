// Copyright 2021 Nikita Naumov
#include "Student.h"

Student::Student(unsigned id, std::string fio) {
  this->id = id;
  this->fio = fio;
  this->group = nullptr;
}

Student::~Student() {
  this->marks.clear();
  this->fio.clear();
  this->group = nullptr;
}

void Student::addToGroup(Group* destinationGroup) {
  this->group = destinationGroup;
}
void Student::addMarkToStudent(int newMark) {
  this->marks.push_back(newMark);
}
void Student::getInfo() {
  std::cout << "FIO = " << this->fio << std::endl;
  std::cout << "ID = " << this->id << std::endl;
  if (this->group != nullptr) {
    std::cout << "Group " << (this->group->getTitle()) << std::endl;
  } else {
    std::cout << "Group " << "None" << std::endl;
  }
}
void Student::printMarks() {
  for (size_t i = 0; i < this->marks.size(); ++i) {
    std::cout << this->marks[i] << "\t";
  }
  std::cout << std::endl;
}
double Student::getAverageMark() {
  double averageMark = 0;
  for (size_t i = 0; i < this->marks.size(); ++i) {
    averageMark += this->marks[i];
  }
  return (averageMark / (double)this->marks.size());
}
