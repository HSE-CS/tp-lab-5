// Copyright 2021 ArinaMonicheva

#ifndef INCLUDE_DEANERY_H_
#define INCLUDE_DEANERY_H_

#include <fstream>
#include <string>
#include <vector>
#include "Group.h"

typedef struct Statistics {
  const Group* bestGroup;
  double bestGrAvMark;
  const Student* bestStudent;
  double bestStAvMark;
  double groupsAverage;
} stats;

class Deanery {
 private:
  std::vector<Group*> groups;

 public:
  void createGroups(std::ifstream &groupsFile);
  void hireStudents(std::ifstream &studentsFile);
  void addMarksToAll();
  stats& getStatistics();
  void moveStudents(Student& toMove, Group& destination);
  void fireStudents();
  void safeStaff(std::ofstream &groupFile, std::ofstream &studentFile);
  void initHeads(Group& Where);
  void printToConsole(Student& toPrint);
  void printToConsole(Group& toPrint);
  void printToConsole(stats& toPrint);
  const std::vector<Group*> getGroups();
  void addNewGroup(Group* newGroup);
  ~Deanery();
};

#endif  // INCLUDE_DEANERY_H_
