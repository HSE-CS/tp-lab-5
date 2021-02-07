// Copyright 2021 Pavlova D.
#include "../include/Deanary.h"

void Deanary::createGroups() {
  std::ifstream group_data("../src/data/groups.txt");

  std::string group_name;
  std::string spec_name;

  if (group_data.is_open()) {
    while (!group_data.eof()) {
      group_data >> group_name;
      group_data >> spec_name;
      groups.push_back(new Group(group_name, spec_name));
    }
  }
}

void Deanary::hireStudents() {
  std::ifstream students_data("../src/data/students.txt");
  std::string tmp;
  std::string group_name;
  std::string student_name;
  int id = 0;

  if (students_data.is_open()) {
    students_data >> tmp >> group_name;
    getline(students_data, student_name);
    while (!students_data.eof()) {
      getline(students_data, student_name);
      if (!student_name.empty()) {
        for (auto group : this->groups)
          if (group->getTitle() == group_name)
            group->addStudents(new Student(id++, student_name));
      } else {
        students_data >> tmp >> group_name;
        getline(students_data, student_name);
      }
    }
  }
}

void Deanary::addMarksToAll(int count) {
  for (auto group : this->groups) {
    for (auto student : group->students) {
      for (int i = 0; i < count; ++i)
        student->addMark(rand_int() % 10);
    }
  }
}

void Deanary::getStatistics() {
  for (auto group : this->groups) {
    std::cout << "Group: " << group->getTitle() << " (" << group->getSpec()
              << ")" << std::endl
              << "Average mark in group: " << group->getAverageMark()
              << std::endl;
  }

  for (auto group : this->groups) {
    std::cout << "Group: " << group->getTitle() << std::endl
              << "A-students: " << std::endl;
    for (auto student : group->students) {
      if (student->getAverageMark() >= 8)
        std::cout << student->getID() << ". " << student->getFIO() << ": "
                  << student->getAverageMark() << std::endl;
    }
  }

  for (auto group : this->groups) {
    std::cout << "Group: " << group->getTitle() << std::endl
              << "Worst students: " << std::endl;
    for (auto student : group->students) {
      if (student->getAverageMark() <= 4)
        std::cout << student->getID() << ". " << student->getFIO() << ": "
                  << student->getAverageMark() << std::endl;
    }
  }
}

void Deanary::moveStudents(int id, const std::string &title) {
  for (auto group_new : groups) {
    if (group_new->getTitle() == title) {
      for (auto group_old : groups) {
        for (auto student : group_old->students) {
          if (student->getID() == id) {
            group_new->addStudents(student);
            group_old->removeStudent(id);
            std::cout << student->getFIO() << " was moved" << std::endl;
            return;
          }
        }
      }
    }
  }
}

void Deanary::saveStaff() {
  std::ofstream data("../src/data/stuff.txt");
  for (auto group : this->groups) {
    data << "Group: " << group->getTitle() << std::endl;
    for (auto student : group->students) {
      data << student->getID() << ". " << student->getFIO() << std::endl;
    }
    data << std::endl;
  }
}

void Deanary::initHeads() {
  for (auto group : this->groups) {
    group->chooseHead();
  }
}

void Deanary::fireStudents(int _id) {
  for (auto group : this->groups) {
    for (auto student : group->students) {
      if (student->getID() == _id)
        group->removeStudent(student->getID());
      std::cout << student->getFIO() << " was fired" << std::endl;
    }
  }
}

void Deanary::fireStudents() {
  for (auto group : this->groups) {
    for (auto student : group->students) {
      if (student->getAverageMark() < 4) {
        group->removeStudent(student->getID());
        std::cout << student->getFIO() << " was fired" << std::endl;
      }
    }
  }
}
