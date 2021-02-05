//  Copyright © 2021 Ksuvot. All rights reserved.

#include <ctime>
#include <random>
#include <fstream>
#include <iostream>
#include "Deanary.h"

void Deanary::saveData() {
  std::ofstream groupList("List_of_groups.txt");
  if (groupList.is_open()) {
    for (auto group : groups) {
      groupList << group->title << "\n";
    }
  }

  for (auto group : groups) {
    std::ofstream studentsList(group->title + ".txt");
    for (auto student : group->students)
      studentsList << student->fio << "\n";
  }
}

void Deanary::initHeadmen() {
  for (auto group : groups)
    group->chooseHeadmen();
}

void Deanary::createGroups() {
  std::ifstream groupsList("List_of_groups.txt");
  if (groupsList.is_open()) {
    while (!groupsList.eof()) {
      std::string name;
      groupsList >> name;
      if (name.size() == 0)
        continue;
      groups.push_back(new Group(name, "output"));
    }
  }
  groupsList.close();
}

void Deanary::getStatistics() {
  for (auto group : groups)
    for (auto student : group->students)
      std::cout << student->fio << " [average mark]: "
                << student->getAverageMark() << std::endl;
}

void Deanary::createStudents() {
  for (auto group : groups) {
    std::ifstream students(group->title + ".txt");
    if (students.is_open()) {
      int i = 0;
      while (!students.eof()) {
        char *name = new char[9999];
        students.getline(name, 9999, '\n');
        if (name[0] == '\0')
          continue;
        group->setStudent(new Student(i++, std::string(name)));
      }
    }
  }
}

void Deanary::setRandomMarks() {
  std::srand(time(0));
  for (auto group : groups)
    for (auto student : group->students)
      for (int i = 0; i < 10; i++)
        student->setMark(std::rand() % 11 + 1);
}

void Deanary::expulsionStudents() {
  for (auto group : groups)
    for (auto student : group->students)
      if (student->getAverageMark() < 4)
        student->group->removeStudent(student);
}

void Deanary::moveStudent(Student *student, Group *group) {
  student->group->removeStudent(student);
  group->setStudent(student);
}
