// Copyright 2020 me
#include "../include/Group.h"
#include "../include/Student.h"

void Group::addStudent(Student *new_student) {
  new_student->group = this;
  students->push_back(new_student);
}

void Group::chooseHead() {
  head = students->at(std::rand() % students->size());
  head->isHead = true;
}

void Group::removeStudent(unsigned st_id) {
  for (size_t i = 0; i < students->size(); ++i) {
    if (students->at(i)->id == st_id) {
      if (students->at(i)->isHead) {
        students->at(i)->isHead = false;
        students->erase(students->begin() + i);
        chooseHead();
      } else {
        students->erase(students->begin() + i);
      }
    }
  }
}

void Group::removeStudent(Student *st) {
  unsigned st_id = st->id;
  removeStudent(st->id);
}

double Group::getAveragemark() {
    double ans = 0.0;
    for (auto st : *students) {
      ans += st->getAveragemark();
    }
    if (isEmpty()) {
      return 0.0;
    } else {
      return ans / students->size();
    }
}

Student *Group::getStudentById(unsigned id) {
    for (auto st : *students) {
        if (st->id == id) {
            return st;
        }
    }
    return nullptr;
}

std::vector<Student *> Group::containsStudent() {
  std::vector<Student *> *st_list(students);
  return *st_list;
}

Student *Group::getHead() { return head; }

bool Group::isEmpty() {
  if (students->size() == 0)
    return true;
  else
    return false;
}
