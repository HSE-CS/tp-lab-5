// Copyright 2021 ArinaMonicheva

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

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
  void moveStudents(const Student& toMove, const Group& destination);
  void fireStudents();
  void safeStaff(std::ofstream &groupFile, std::ofstream &studentFile);
  void initHeads(const Group& Where);
  void printToConsole(const Student& toPrint);
  void printToConsole(const Group& toPrint);
  void printToConsole(const stats& toPrint);
  const std::vector<Group*> getGroups();
  void addNewGroup(Group* newGroup);
  ~Deanery();
};

#endif  // INCLUDE_DEANARY_H_
