//Copyright 2021 Nikita Naumov
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
double Student::getAverageMark() {
    double averageMark = 0;
    for (size_t i = 0; i < this->marks.size(); ++i) {
        averageMark += this->marks[i];
    }
    return (averageMark / (double)this->marks.size());
}
