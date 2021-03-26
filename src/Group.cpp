// Copyright 2021 PaninaPolina
#include "Student.h"
#include "Group.h"
#include "Deanary.h"
#include <algorithm>
#include <iostream>
#include <string>

Group::Group(std::string name) { title = name; }

void Group::addStudent(Student* Groupmember) {
  students.push_back(Groupmember);
  num = students.size();
}

Student* Group::electHead() {
  int i = std::rand() % (num - 1) + 0;
  head = students[i];
  return students[i];
}

Student* Group::searchSfio(std::string name) {
  for (int i = 0; i < num; i++) {
    if (students[i]->fio == name) {
      return students[i];
    }
  }
}

Student* Group::searchSid(int numid) {
  for (int i = 0; i < num; i++) {
    if (students[i]->id == numid) {
      return students[i];
    }
  }
}

float Group::averageGroup() {
  int sum = 0;
  for (int i = 0; i < num; i++) {
    sum += students[i]->averageMark();
  }
  return sum / num;
}

void Group::exceptionStudent(std::string name) {
  for (int i = 0; i < num; i++) {
    if (students[i]->fio == name) {
      if (students[i] == head) {
        students.erase(students.begin() + i);
        num--;
        electHead();
      } else {
        students.erase(students.begin() + i);
        num--;
      }
    }
  }
}
