//  Copyright 2021 Nikita Naumov
#include "Student.h"

Student::Student(unsigned id, std::string fio) {
  this->id = id;
  this->fio = fio;
  this->group = nullptr;
  this->isHead = false;
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
void Student::printInfoAboutStudent() {
  std::cout << "FIO = " << this->fio << std::endl;
  std::cout << "ID = " << this->id << std::endl;
  if (this->group != nullptr) {
    std::cout << "Group " << (this->group->getTitle()) << std::endl;
  } else {
    std::cout << "Group " << "None" << std::endl;
  }
  if (this->group != nullptr) {
    std::cout << "Are they a head of group: ";
    if (this->isHead) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  }

}
void Student::printMarks() {
  if (this->marks.size()) {
    for (size_t i = 0; i < this->marks.size(); ++i) {
      std::cout << this->marks[i] << "\t";
    }
    std::cout << std::endl;
  } else {
    std::cout << "The student have no one mark now\n";
  }
}
double Student::getAverageMark() {
  if (!(this->marks.size())) {
    return -1;
  }
  double averageMark = 0;
  for (size_t i = 0; i < this->marks.size(); ++i) {
    averageMark += this->marks[i];
  }
  return (averageMark / (double)this->marks.size());
}
void Student::makeHead() { this->isHead = true; }
unsigned Student::getId() { return (this->id); }
bool Student::isTheyHead() { return (this->isHead); }
