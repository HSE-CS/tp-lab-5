// Copyright 2020 S. BOR

#include "Deanary.h"
#include <random>
#include <time.h>
#include <iostream>
#include <fstream>

void Deanary::createGroups() {
  std::ifstream groupsList("group.txt");
  if (groupsList.is_open()) {
    while (!groupsList.eof()) {
      std::string name;
      groupsList >> name;
      if (name.size() == 0)
        continue;
      groups.push_back(new Group(name, "progs"));
    }
  }
  groupsList.close();
}

void Deanary::createStudents() {
  for (auto group: groups) {
    std::ifstream students(group->title + ".txt");
    if (students.is_open()) {
      int i = 0;
      while (!students.eof())
      {
        char *name = new char[50];
        students.getline(name, 50, '\n');
        if (name[0] == '\0')
          continue;
        group->addStudent(new Student(i++, std::string(name)));
      }
    }
  }
}

void Deanary::AddRandomMarks() {
  std::srand(time(0));
  for (auto group: groups)
    for (auto student: group->students)
      for (int i = 0; i < 10; i++)
        student->addMark(std::rand() % 11 + 1);
}
void Deanary::GetStatistics() {
  for (auto group: groups)
    for (auto student: group->students)
      std::cout << student->fio << " average mark: " << student->getAvarageMark() << std::endl; 
}

void Deanary::moveStudent(Student *student, Group *dest) {
  student->group->removeStudent(student);
  dest->addStudent(student);
}

void Deanary::initHeads() {
  for (auto group: groups)
    group->chooseHead();
}

void Deanary::saveStaff() {
  std::ofstream groupList("group.txt");
  if (groupList.is_open()) {
    for (auto group: groups) {
      groupList << group->title << "\n";
    }
  }
  for (auto group: groups) {
    std::ofstream studentsList(group->title + ".txt");
      for (auto student: group->students) 
        studentsList << student->fio << "\n";
  }
}

void Deanary::fireStudents() {
  for (auto group: groups)
    for (auto student: group->students)
      if (student->getAvarageMark() < 4)
        student->group->removeStudent(student);
}
