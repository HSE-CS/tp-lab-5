// Copyright 2020 Konina Tatiana
#include<iostream>
#include "Group.h"
#include "Student.h"
Group::Group(std::string spec, unsigned int groupNum) {
  this->spec = spec;
  this->title = groupNum;
  this->head = NULL;
}

bool Group::addStudent(Student* st) {
  if (students.count(st->getId())) {
    std::cout << "Probabilty of Student" << st->getFio()
      << "beeing already in group" << std::endl;
    return true;
  } else {
    if (students.size() == 20) {
      std::cout << "group is full" << std::endl;
      return false;
    } else {
      students.emplace(st->getId(), st);
      st->addToGroup(this);
      return true;
    }
  }
}

void Group::chooseHead() {
  double maxAverage = 0;
  unsigned int idBestStudent;
  for (std::map<unsigned int, Student*>::iterator it =
       students.begin(); it != students.end(); ++it) {
    if (maxAverage < it->second->getAverage()) {
      maxAverage = it->second->getAverage();
      idBestStudent = it->first;
    }
  }
  head = students[idBestStudent];
  students[idBestStudent]->initHead();
}


bool Group::isEmpty() {
  return students.size();
}

bool Group::removeStudent(unsigned int id) {
  if (students[id]) {
    students[id]->addToGroup(nullptr);
    students.erase(id);
    if (getHead() == -1) {
      chooseHead();
    }
    return true;
  }
  std::cout << "Student do not exist";
  return false;
}
double Group::getAverageMarks() {
  double average = 0;
  for (std::map<unsigned int, Student*>::iterator it =
       students.begin(); it != students.end(); ++it) {
    average += it->second->getAverage();
  }
  return average / students.size();
}
Student* Group::search(unsigned int id) {
  if (students.count(id)) {
    return students[id];
  } else {
    std::cout<< "Student do not exist";
    return nullptr;
  }
}
int Group::getHead() {
  for (std::map<unsigned int, Student*>::iterator it =
       students.begin(); it != students.end(); ++it) {
    if (it->second->isHeadOfGroup()) {
      return it->first;
    }
  }
  return -1;
}

std::map <unsigned int, Student*> Group::getStudents() {
  return students;
}

std::string Group::getSpec() const {
  return this->spec;
}
unsigned int Group::getTitle() const {
  return this->title;
}

int Group::getGroupSize() {
  return students.size();
}

