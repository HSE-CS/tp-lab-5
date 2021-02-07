//  Copyright 2021 Nikita Naumov
#include "Group.h"
#include "Student.h"

Group::Group(std::string title) {
    this->title = title;
    this->head = nullptr;
}
Group::~Group() {
    this->title.clear();
    this->spec.clear();
    this->head = nullptr;
    this->students.clear();
}
void Group::addStudentToGroup(Student* studentToAdd) {
    studentToAdd->addToGroup(this);
    this->students.push_back(studentToAdd);
}
std::string Group::getTitle() { return this->title; }
void Group::setHead(Student* newHead) {
    if (this->head == nullptr) {
        (*newHead).makeHead();
        this->head = newHead;
    } else if ((this->head) == (newHead)) {
        return;
    } else {
      unsigned oldHead = (this->head)->id;
      unsigned oldHeadId = -1;
      for (size_t i = 0; i < this->students.size(); ++i) {
        if ((this->students[i])->id == oldHead) {
          oldHeadId = i;
          break;
        }
      }
      (this->students[oldHeadId])->isHead = false;
      (*newHead).makeHead();
      this->head = nullptr;
      this->head = newHead;
    }
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
  if (!(this->students.size())) {
    return -1;
  }
  double averageGroupMark = 0;
  for (size_t i = 0; i < this->students.size(); ++i) {
    averageGroupMark += (this->students[i])->getAverageMark();
  }
  return averageGroupMark / static_cast<double>(this->students.size());
}
void Group::fireStudentFromGroup(unsigned id) {
    bool isInGroup = findStudentByID(id);
    unsigned neededInd = -1;
    if (!isInGroup) {    //  Handle exception if student is not in the group
      std::cout << "This student is not in current group\n";
      return;
    }

    for (size_t i = 0; i < this->students.size(); ++i) {
        if ((this->students[i])->id == id) {
            neededInd = i;
        }
    }
    (this->students[neededInd])->group = nullptr;
    if ((this->students[neededInd])->isHead) {
        (this->students[neededInd])->isHead = false;
        this->head = nullptr;
    }
    this->students.erase(students.begin() + neededInd);
}
void Group::printInfoAboutGroup() {
  std::cout << "Group name : " <<this->title << std::endl;
  std::cout << "Group specialty : " << this->spec << std::endl;
  std::cout << "Amount of students: " << this->students.size() << std::endl;
  std::cout << "Current group head [ ";
  if (this->head == nullptr) {
    std::cout << "None" << " ] " << std::endl;
  } else {
    std::cout << "FIO : " << (this->head)->fio << "\t" <<
        "| ID : " <<(this->head)->id << " ] " << std::endl;
  }
}
