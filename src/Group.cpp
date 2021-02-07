// Copyright 2020 LongaBonga
#include "Group.h"

#include <iostream>
#include <string>
#include <vector>

Group::Group(std::string tl, std::string sp) {
  title = tl;
  spec = sp;
  head = NULL;
  students = new std::vector<Student*>();
}

void Group::addStudent(Student* person) { students->push_back(person); }

void Group::chooseHead() {
  Student& person = *students->at(0);
  person.isHead = true;
  head = &person;
}

void Group::removeStudent(Student* student) {
  for (int i = 0; i < students->size(); ++i) {
    if (students->at(i)->getId() == student->getId()) {
      if (student->isHead) {
        students->erase(students->begin() + i);
        chooseHead();

        std::cout << "New Head is: " << head->getName() << "\n";
      } else {
        students->erase(students->begin() + i);
      }
    }
  }
}

float Group::getAveragemark() {
  float summ = 0;
  for (auto person : *students) summ += person->getAveragemark();
  return summ / students->size();
}

Student& Group::getStudent(int id) {
  for (auto* student : *students) {
    if (student->getId() == id) {
      return *student;
    }
  }
}

Student& Group::getStudent(std::string name) {
  for (auto* student : *students) {
    if (student->getName() == name) return *student;
  }
}

std::vector<Student *> *Group::getStudents() const {
    return students;
}

bool Group::isEmpty() { return students->empty(); }

std::string Group::getTitle() { return title; }

Student* Group::getHead() { return head; }
