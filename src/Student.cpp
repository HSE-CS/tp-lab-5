// Copyright Nikita Demashow 2021
#include "Student.h"
#include "Group.h"
Student::Student(const std::string newFio, const unsigned int newId) {
  fio = newFio;
  id = newId;
  srand(rand());
  iq = rand() % 40 + 90;
 }
double Student::getAverageMark() const {
  double sum{0};
  for (auto mark : marks) {
    sum += mark;
  }
  return sum / marks.size();
}
bool Student::isHeadOfGroup() const { return id == group->getHead()->id; }
void Student::addMark(const int16_t newMark) { marks.push_back(newMark); }
void Student::addToGroup(Group* newGroup) { group = newGroup; }
unsigned int Student::getId() const { return this->id; }
std::string Student::getFio() const { return this->fio; }
std::string Student::getMarks() const {
  std::stringstream smarks;
  for (size_t i{0}; i < marks.size(); ++i) {
    smarks << marks[i];
    if (i != marks.size() - 1) {
      smarks << ' ';
    }
  }
  return smarks.str();
}