// Copyright 2021 Smirnov Grigory
#include "Deanery.h"

void Deanery::initHeads() {
  if (groups.empty())
    throw "There are no groups";
  for (int i = 0; i < groups.size(); i++)
    groups[i]->chooseHead();
}

explicit Deanery::Deanery(std::vector<Group*> forAdd) {
  for (auto group : forAdd)
    this->groups.push_back(group);
}

Group* Deanery::getGroup(std::string title) {
  for (auto group : groups)
    if (group->getTitle() == title)
      return group;
  throw "Incorrect title";
}

void Deanery::addRandomMarks(int n) {
  if (groups.empty())
    throw "There are no groups";
  for (auto group : groups)
    for (auto student : group->students) {
      std::random_device seed;
      int modificator = seed() % 5;
      int isBad = seed() % 2;
      if (isBad) {
        for (int i = 0; i < n; i++)
          student->addMark(seed() % (10 - modificator));
      } else {
        for (int i = 0; i < n; i++)
          student->addMark((seed() % (10 - modificator)) + modificator + 2);
       }
    }
}

void Deanery::academicPerformance() {
  if (groups.empty())
    throw "There are no groups";
  for (int i = 0; i < groups.size(); i++) {
    if (!(groups[i]->isEmpty())) {
      std::cout << std::endl << groups[i]->getTitle() +
        "   Average mark: " +
        std::to_string(groups[i]->getAverageMark()) << std::endl;
      for (auto student : groups[i]->students)
        std::cout << student->getFio() + "  " +
        std::to_string(student->getAverageMark()) << std::endl;
    }
  }
}

void Deanery::moveStudent(Student* forMove,
  std::string oldGroup, std::string newGroup) {
  getGroup(oldGroup)->removeStudent(forMove->getFio());
  if (forMove->isHeadOfGroup())
    getGroup(oldGroup)->chooseHead();
  getGroup(newGroup)->addStudent(forMove);
}

void Deanery::fireWeakStudents() {
  if (groups.empty())
    throw "There are no groups";
  for (auto group : groups)
    for (auto student : group->students)
      if ((student->getAverageMark() - 3.5) < 0.00001) {
        group->removeStudent(student->getFio());
        if (student->isHeadOfGroup())
          group->chooseHead();
      }
}

void Deanery::saveStaff(std::string path) {
  std::ofstream file(path);
  if (groups.empty())
    throw "There are no groups";
  for (int i = 0; i < groups.size(); i++) {
    if (!(groups[i]->isEmpty())) {
      file << std::endl << groups[i]->getSpec() <<
        std::endl << groups[i]->getTitle() << std::endl;
      for (auto student : groups[i]->students)
        file << student->getFio() << std::endl;
    }
  }
  file << "EOF";
}

void Deanery::printInfo() {
  if (groups.empty())
    throw "There are no groups";
  for (int i = 0; i < groups.size(); i++) {
    if (!(groups[i]->isEmpty())) {
      std::cout << std::endl << groups[i]->getTitle() +
        "   Average mark: " + std::to_string(groups[i]->getAverageMark())
        << std::endl;
      std::cout << "Head:  " << groups[i]->getHead()->getFio() << std::endl;
      for (auto student : groups[i]->students)
        std::cout << std::to_string(student->getId()) + " "
        + student->getFio() + "  Mark:  " +
        std::to_string(student->getAverageMark()) << std::endl;
    }
  }
}
