// Copyright 2021 Andrey Bakurskii

#include "Deanary.h"

void Deanary::createGroups(std::string filename) {
  std::ifstream in(filename);
  std::string title, spec;
  int numStudents, id;
  if (in.is_open()) {
    while (in >> title >> spec >> numStudents) {
      Group* new_group = new Group(title, spec);
      for (int k = 0; k < numStudents; k++) {
        in >> id;
        for (size_t i = 0; i < this->students.size(); i++) {
          if (this->students[i]->getId() == id) {
            new_group->addStudent(this->students[i]);
          }
        }
      }
      this->groups.push_back(new_group);
    }
  }
}

void Deanary::hireStudents(std::string filename) {
  std::ifstream in(filename);
  int id;
  std::string f, i, o;
  if (in.is_open()) {
    while (in >> id >> f >> i >> o) {
      Student* new_student = new Student(id, f + " " + i + " " + o);
      this->students.push_back(new_student);
    }
  }
}

void Deanary::addMarksToAll() {
  for (size_t i = 0; i < this->students.size(); i++) {
    for (int j = 0; j < 5; j++) {
      this->students[i]->addmark(std::rand() % 10 + 1);
    }
  }
}

void Deanary::getStatistics() {
  bool statistic = true;
  for (size_t i = 0; i < this->groups.size(); i++) {
    this->groups[i]->printGroup(statistic);
    std::cout << std::endl;
  }
}

void Deanary::moveStudents(Student* student, Group* new_group) {
  student->group->removeStudent(student);
  new_group->addStudent(student);
}

void Deanary::saveStaff(std::string filename) {
  std::ofstream out(filename);
  if (out.is_open()) {
    for (size_t i = 0; i < this->groups.size(); i++) {
      out << this->groups[i]->getGroupAsString() << std::endl;
    }
  }
}

void Deanary::initHeads() {
  for (size_t i = 0; i < this->groups.size(); i++) {
    this->groups[i]->chooseHead();
  }
}

void Deanary::fireStudents(float mark) {
  for (size_t i = 0; i < this->groups.size(); i++) {
    for (size_t j = 0; j < this->groups[i]->students.size(); j++) {
      if (this->groups[i]->students[j]->getAveragemark() < mark) {
        this->groups[i]->removeStudent(this->groups[i]->students[j]);
      }
    }
  }
}

void Deanary::printStudents() {
  for (size_t i = 0; i < this->students.size(); i++) {
    std::cout << this->students[i]->getId() << " "
        << this->students[i]->getFIO() << "\n";
  }
}

void Deanary::printGroups() {
  bool statistic = false;
  for (size_t i = 0; i < this->groups.size(); i++) {
    this->groups[i]->printGroup(statistic);
    std::cout << std::endl;
  }
}
