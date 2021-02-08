#include "Deanary.h"
// Copyright 2020 Polina Lukicheva

Deanary::Deanary() {
  id = 0;
  std::vector<Group*> groups();
}

void Deanary::createGroups(std::string file) {
  std::ifstream ifile(file);
  std::string title, spec;

  ifile >> title;
  ifile >> spec;

  while (title != "") {
    groups.push_back(new Group(title, spec));
    ifile >> title;
    ifile >> spec;
  }
}

void Deanary::hireStudents(std::string file) {
  std::ifstream ifile(file);
  std::string fio;
  ifile >> fio;
  for (auto group : groups)
    while (fio != "") {
      group->students.push_back(new Student(++id, fio));
      ifile >> fio;
    }
  }

void Deanary::addMarksToAll() {
  for (auto group : groups)
    for (auto student : group->students)
      for (int i = 0; i < std::rand() % 15; ++i)
        student->addmark(std::rand() / 11);
}

void Deanary::getStatistics(std::string file) {
  for (auto group : this->groups) {
    for (auto student : group->students)
      std::cout << student->getFio() <<
      " " << student->averageMark() << std::endl;
    std::cout << std::endl;
  }
}

void Deanary::moveStudents(Student* student, Group* group) {
  student->group->removeStudent(student);
  group->addStudent(student);
}

void Deanary::saveStaff(std::string grFile, std::string stFile) {
  std::ofstream oGrFile(grFile);
  std::ofstream oStFile(stFile);
  for (auto group : groups) {
    oGrFile << group->title << std::endl << group->spec << std::endl;
    for (auto student : group->students)
      oStFile << student->fio << std::endl;
  }
}

void Deanary::initHeads() {
  for (auto group : groups)
    group->chooseHead();
}

void Deanary::fireStudents() {
  for (auto& group : groups)
    for (auto& student : group->students)
      if (student->averageMark() < 3.50)
        group->removeStudent(student);
}
