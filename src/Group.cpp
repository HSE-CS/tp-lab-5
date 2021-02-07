// Copyright Nikita Demashow 2021
#include"Group.h"
#include"Student.h"
Student* Group::getHead() const { return head; }
bool Group::isFull() { return students.size() == limit; }
bool Group::isEmpty() { return !students.size(); }
void Group::addStudent(Student* newSt) {
  students.push_back(newSt);
}
double Group::getAverageMark() {
  double sum{0};
  for (auto student : students) {
    sum += student->getAverageMark();
  }
  return sum / students.size();
}
void Group::choseHead() {
  srand(rand());
  unsigned int seed = 1;
  unsigned int indHead = rand_r(&seed) % students.size();
  this->head = students[indHead];
}
void Group::removeStudent(std::string fio) {
  for (size_t i{0}; i < students.size(); ++i) {
    if (students[i]->getFio() == fio) {
     students.erase(students.begin() + i);
    }
  }
}
Student* Group::getStudentById(const unsigned int id) {
  for (auto student : students) {
    if (student->getId() == id) {
      return student;
    }
  }
  return NULL;
}
Student* Group::getStudentByFio(const std::string fio) {
  for (auto student : students) {
    if (student->getFio() == fio) {
      return student;
    }
  }
  return NULL;
}
std::string Group::getSpec() const { return this->spec; }
std::string Group::getTitle() const {return this->title;}
