//  Copyright 2020 GHA created by Klykov Anton

#include "Group.h"
#include <random>


void Group::addStudent(Student* st) {
  students.push_back(st);
  st->addToGroup(this);
}
void Group::chooseHeader() {
  if (header != nullptr) {
    return;
  }
  std::random_device rd;
  std::mt19937 mersenne(rd());
  header = students[(static_cast<unsigned int>((mersenne() % students.size())))];
  header->isHead = true;
}
Student* Group::removeStudent(Student *st) {
  if (st == nullptr) {
    return nullptr;
  }
  if (!(this->isEmpty())) {
    for (size_t i = 0; i < students.size(); ++i) {
      if (st->getId() == students[i]->getId()) {
        if (students[i]->isHead) {
          students.erase(students.begin() + i);
          st->group = nullptr;
          st->isHead = false;
          chooseHeader();
          return st;
        } else {
          students.erase(students.begin() + i);
          st->group = nullptr;
          return st;
        }
      }
    }
  } else {
    return nullptr;
  }
}
double Group::getAverageMark() {
  double averageInGroup{0};
  for (const auto & student : students) {
    averageInGroup += student->getAverageMark();
  }
  return (averageInGroup / students.size());
}
Student* Group::getStudent(int _id) {
  for (size_t i = 0; i < students.size(); ++i) {
    if (_id == students[i]->getId()) {
      return students[i];
    }
  }
  return nullptr;
}
bool Group::containsStudent(Student *st) {
  for (size_t i = 0; i < students.size(); ++i) {
    if (st->getId() == students[i]->getId()) {
      return true;
    }
  }
  return false;
}
bool Group::isEmpty() const {
  return !(students.size());
}
bool Group::delStudent(Student *st) {
  if (st == nullptr) {
    return false;
  }
  for (size_t i = 0; i < students.size(); ++i) {
    if (st->getId() == students[i]->getId()) {
      if (students[i]->isHead) {
        this->students.erase(students.begin() + i);
        st->group = nullptr;
        st->marks.clear();
        st->isHead = false;
        st->id = -1;
        header = nullptr;
        chooseHeader();
        return true;
      } else {
        this->students.erase(students.begin() + i);
        st->group = nullptr;
        st->marks.clear();
        return true;
      }
    }
  }
}
std::string Group::getTitle() {
  return title;
}
Group::Group(const std::string& _title) {
  title = _title;
  special_on = "IMIKN";
  header = nullptr;
}
Student* Group::getHeader() {
  return header;
}
std::vector<Student *> Group::getStudentsInGroup() {
  return students;
}

