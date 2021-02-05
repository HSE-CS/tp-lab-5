//Copyright 2021 Nikita Naumov
#include "Group.h"
#include "Student.h"

Group::Group(std::string title) { 
    this->title = title;
    this->spec = (std::string) "spec"; 
    this->head = nullptr;
}
Group::~Group() { 
    this->title.clear();
    this->head = nullptr;
    this->students.clear();
}  
void Group::addStudentToGroup(Student* studentToAdd) {
    studentToAdd->addToGroup(this);
    this->students.push_back(studentToAdd);
}
std::string Group::getTitle() { return this->title; }
void Group::setHead(Student* newHead) { 
    (*newHead).makeHead();
    this->head = newHead;
}
bool Group::findStudentByID(unsigned id) { 
    for (size_t i = 0; i < this->students.size(); ++i) {
        if ((this->students[i])->id == id) {
            return true;
        }
    }
    return false;
}
bool Group::findStudentByFIO(std::string fio) {
    for (size_t i = 0; i < this->students.size(); ++i) {
        if ((this->students[i])->fio == fio) {
            return true;
        }
    }
    return false;
}
double Group::getAverageGroupMark() {
  double averageGroupMark = 0;
  for (size_t i = 0; i < this->students.size(); ++i) {
    averageGroupMark += (this->students[i])->getAverageMark();
  }
  return averageGroupMark / (double)this->students.size();
}
void Group::fireStudentFromGroup(unsigned id) { 
    bool isInGroup = findStudentByID(id);
    unsigned neededInd = -1;
    if (!isInGroup) {    //Handle exception if student is not in the group
      std::cout << "This student is not in current group";
      return;
    }

    for (size_t i = 0; i < this->students.size(); ++i) {
        if ((this->students[i])->id == id) {
            neededInd = i;
        }
    }
    (this->students[neededInd])->group = nullptr;
    this->students.erase(students.begin() + neededInd);
}
void Group::printInfoAboutGroup() {
  std::cout << this->title << std::endl;
  std::cout << this->spec;
  std::cout << "Amount of students " << this->students.size() << std::endl;
  std::cout << "Current group head [ ";
  if (this->head == nullptr) {
    std::cout << "None" << " ] " << std::endl;
  } else {
    std::cout << (this->head)->fio << "\t" << (this->head)->id
        << " ] " << std::endl;
  }
}