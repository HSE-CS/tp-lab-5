// Copyright 2021 Kuznetsov Mikhail
#include "Deanary.h"

void Group::createGroups(std::string filename) {

}
void Group::hireStudents(std::string filename) {
  std::ifstream fin(filename);
  std::string input;
  unsigned int curr_id = 0;
  while (getline(fin, input)) {
      Student(curr_id++, input);
  }
  fin.close();
}
void Group::addMarksToAll();
void Group::getStatistics();
void Group::moveStudents();
void Group::saveStaff();
void Group::initHeads() {
  for (auto g : groups) {
    g->chooseHead();
  }
}
void Group::fireStudents();
