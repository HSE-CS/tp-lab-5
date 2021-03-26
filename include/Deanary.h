// Copyright 2021 PaninaPolina
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include "Group.h"
#include "Student.h"
#include <string>
#include <vector>
#include <iostream>
#include <utility>

class Deanery {
 private:
  std::vector<Student*> students;
  std::vector<Group*> groups;
  std::string fileStudents;
  std::string fileGroups;
  int numSt;
  int numGr;
  std::vector<std::pair<float, std::string>> StStat;
  std::vector<std::pair<float, std::string>> GrStat;
 public:
  Deanery(std::string, std::string);
  void CreateStudents();
  void CreateGroups();
  void addMarks();
  void getStatistics(std::string);
  void changeGroup(std::string, std::string);
  void exceptionStudent();
  void update(std::string);  // update info in file
  void electGhead();
  void printinfo();
};

#endif  // INCLUDE_DEANARY_H_
