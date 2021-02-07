// Copyright 2021 Bulatov D.
#include "Deanary.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


void Deanary::createGroups() {
  std::string s;
  std::ifstream file("groups.txt");
  while (getline(file, s)) {
    std::string s2;
    getline(file, s2);
    Group gr(s, s2);
    groups.push_back(gr);
  }
}

void Deanary::addGroup(const Group& group) { groups.push_back(group); }

std::vector<Group> Deanary::getGroups() { return groups; }

void Deanary::addStudent(const Student& student) {
  students.push_back(student);
}

void Deanary::hireStudents() {
  int i = 1;
  std::string fio;
  std::ifstream file("students.txt");
  while (getline(file, fio)) {
    Student student(fio, i);
    students.push_back(student);
    i++;
  }
}

void Deanary::addMarks() {
  int count = std::rand() % 30;
  std::vector<int> marks;
  for (int i = 0; i < students.size(); i++) {
    for (int j = 0; j < count; j++) {
      marks.push_back(std::rand() % 10);
    }
    students[i].setMarks(marks);
  }
}

std::string Deanary::getStatisticsByStudent(std::string fio) {
  std::stringstream stream;
  for (int i = 0; i < students.size(); i++) {
    if (students[i].getFio() == fio) {
      stream << "FIO: " << fio << ", average mark: "
          << students[i].getAverageMark() << "\n";
      return stream.str();
    }
  }
  return std::string();
}

std::string Deanary::getStatisticsByGroup(std::string spec) {
  std::stringstream stream;
  for (int i = 0; i < groups.size(); i++) {
    if (groups[i].getTitle() == spec) {
      stream << "Title: " << groups[i].getTitle()
             << " spec: " << groups[i].getSpec()
             << " average mark: " << groups[i].getAverageMark() << "\n";
      return stream.str();
    }
  }
  return std::string();
}

void Deanary::moveStudent(std::string fio, std::string spec) {
  for (int i = 0; i < students.size(); i++) {
    if (students[i].getFio() == fio) {
      auto t = students[i].getGroupTitle();
      if (t != "-1") {
        for (int j = 0; j < groups.size(); j++) {
          if (groups[j].getTitle() == t) {
            groups[j].removeStudent(students[i].getId());
          }
        }
      }
      for (int j = 0; j < groups.size(); j++) {
        if (groups[j].getTitle() == spec) {
          groups[j].addStudent(students[i]);
          return;
        }
      }
    }
  }
}

void Deanary::moveStudents() {
  srand(time(NULL));
  for (int i = 0; i < students.size(); i++) {
    int num = std::rand() % (groups.size());
    moveStudent(students[i].getFio(), groups[num].getTitle());
  }
}

void Deanary::fireStudent() {
  for (int i = 0; i < groups.size(); i++) {
    auto students = groups[i].getStudents();
    for (int j = 0; j < students.size(); j++) {
      if (students[j].getAverageMark() < 3) {
        groups[i].removeStudent(students[j].getId());
      }
    }
  }
}

void Deanary::initHead() {
  for (int i = 0; i < groups.size(); i++) {
    groups[i].chooseHead();
  }
}

void Deanary::saveStuff() {
  std::ofstream fout;
  fout.open("output.txt");
  for (int i = 0; i < groups.size(); i++) {
    fout << "-------------Group--------------------" << std::endl;
    fout << "Title: " << groups[i].getTitle()
         << ", spec: " << groups[i].getSpec() << std::endl;
    fout << "Head of group: " << groups[i].getHead()->getFio() << std::endl;
    for (int j = 0; j < groups[i].getStudents().size(); j++) {
      fout << "FIO: " << groups[i].getStudents()[j].getFio() << std::endl;
    }
  }
  fout.close();
}

void Deanary::printInfo() {
  for (int i = 0; i < groups.size(); i++) {
    std::cout << "-------Group---------" << std::endl;
    std::cout << getStatisticsByGroup(groups[i].getTitle()) << std::endl;
    for (int j = 0; j < groups[i].getStudents().size(); j++) {
      std::cout << getStatisticsByStudent(groups[i].getStudents()[j].getFio());
    }
  }
}






