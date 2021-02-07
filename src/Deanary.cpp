// Copyright 2021 ArinaMonicheva

#include <sstream>
#include <iostream>
#include "Deanary.h"

void Deanery::createGroups(std::ifstream &groupsFile) {
  while (!groupsFile.eof()) {
    std::string title;
    std::string spec;
    std::string temp;
    std::getline(groupsFile, temp);
    std::istringstream toVar(temp);
    toVar >> title;
    toVar >> spec;
    Group* tempObj = new Group(title);
    tempObj->spec = spec;
    groups.push_back(tempObj);
  }
}

void Deanery::hireStudents(std::ifstream &studentsFile) {
  time_t* n = NULL;
  unsigned int* whyyy = 0;
  srand(time(n));

  int nGroups = groups.size();
  if (!nGroups) {
    throw "Can't hire students";
  }
  while (!studentsFile.eof()) {
    unsigned id;
    std::string fio = "";
    std::string temp;
    std::getline(studentsFile, temp);
    std::istringstream toVar(temp);
    toVar >> id;
    for (int j = 0; j < 3; j++) {
      toVar >> temp;
      fio = fio + temp + ' ';
    }
    Student* tempObj = new Student(id, fio);
    int Where = rand_r(whyyy) % nGroups;
    groups[Where]->students.push_back(tempObj);
  }
}

void Deanery::addMarksToAll() {
  time_t* n = NULL;
  unsigned int* whyyy = 0;
  srand(time(n));

  for (auto i : groups) {
    for (unsigned j = 0; j < i->students.size(); j++) {
      int times = 5 + rand_r(whyyy) % 5;
      for (int k = 0; k <= times; k++) {
          i->students[j]->addMark(1 + rand_r(whyyy) % 10);
      }
    }
  }
}

stats& Deanery::getStatistics() {
  double curStudMark = groups[0]->students[0]->getAverageMark();
  double curGroupMark = groups[0]->getAverageMark();
  double groupsAver = 0.0;
  Student* currentBestSt = groups[0]->students[0];
  Group* currentBestGr = groups[0];
  int counter = 0;
  for (auto i : groups) {
    double mark = i->getAverageMark();
    if (mark > curGroupMark) {
      curGroupMark = mark;
      currentBestGr = i;
    }
    groupsAver += mark;
    counter++;
    for (int j = 0; j < i->students.size(); j++) {
      mark = i->students[j]->getAverageMark();
      if (mark > curStudMark) {
        curStudMark = mark;
        currentBestSt = i->students[j];
      }
    }
  }
  groupsAver /= counter;
  stats* newStats = new stats{ currentBestGr, curGroupMark,
  currentBestSt, curStudMark, groupsAver };

  return *newStats;
}

void Deanery::moveStudents(Student* toMove, Group* destination) {
  if (toMove->isHeadOfGroup()) {
    toMove->isHead = false;
  }
  if (toMove->group != NULL) {
    toMove->group->removeStudent(toMove);
  }
  destination->addStudent(toMove);
  toMove->addToGroup(destination);
}

void Deanery::fireStudents() {
  for (auto i : groups) {
    for (int j = 0; j < i->students.size(); j++) {
      if (i->students[j]->getAverageMark() < 5.0) {
        if (i->students[j]->isHeadOfGroup()) {
            i->students[j]->isHead = false;
        }
        i->students.erase(i->students.begin() + j);
      }
    }
  }
}

void Deanery::safeStaff(std::ofstream &groupFile, std::ofstream &studentFile) {
  for (auto i : groups) {
    groupFile << i->title << ' ' << i->spec << '\n';
    for (int j = 0; j < i->students.size(); j++) {
      studentFile << i->students[j]->id << ' ' << i->students[j]->fio << '\n';
    }
  }
}

void Deanery::initHeads(Group* Where) {
  double max = Where->students[0]->getAverageMark();
  double current = 0.0;
  int index = 0, currentIndex = 0;
  for (auto i : Where->students) {
    current = i->getAverageMark();
    if (current > max) {
      max = current;
      index = currentIndex;
    }
    currentIndex++;
  }
  // Where.students[index]->isHead = true;
  // Where.head = Where.students[index];
  Where->chooseHead(Where->students[index]);
}

void Deanery::printToConsole(Student* toPrint) {
  std::cout << toPrint->id << " " << toPrint->fio << '\n';
  std::cout << "Group: " << toPrint->group->title;
  if (toPrint->isHead) {
    std::cout << ", head";
  }
  std::cout << '\n';
  std::cout << "Marks: " << std::endl;
  for (auto i : toPrint->marks) {
    std::cout << i << ' ';
  }
  std::cout << "\nAverage mark: " << toPrint->getAverageMark() << std::endl;
}

void Deanery::printToConsole(Group* toPrint) {
  std::cout << "Group: " << toPrint->title << '\n';
  std::cout << "Speciality: " << toPrint->spec << '\n';
  for (auto i : toPrint->students) {
    std::cout << i->id << i->fio << '\n';
  }
  std::cout << "Head: ";
  if (toPrint->head) {
    std::cout << toPrint->head->id << toPrint->head->fio << std::endl;
  } else {
    std::cout << "--" << std::endl;
  }
}

void Deanery::printToConsole(stats* toPrint) {
  std::cout << "Best group: " << toPrint->bestGroup->title << ", "
  << "average " << toPrint->bestGrAvMark << '\n';
  std::cout << "Best student: " << toPrint->bestStudent->id << ' '
  << toPrint->bestStudent->fio << ", average "
  << toPrint->bestStAvMark << '\n';
  std::cout << "Average in all groups: " << toPrint->groupsAverage
  << std::endl;
}

const std::vector<Group*> Deanery::getGroups() {
  return groups;
}

void Deanery::addNewGroup(Group* newGroup) {
  int notHere = true;
  for (auto i : groups) {
    if (i->title == newGroup->title) {
      notHere = false;
    }
  }
  if (notHere) {
    groups.push_back(newGroup);
  }
}
