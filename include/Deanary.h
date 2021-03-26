// Copyright 2021 PaninaPolina
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include "Group.h"
#include "Student.h"
#include <string>
#include <vector>
#include<iostream>
using namespace std;

class Deanery {
 private:
  vector<Student*> students;
  vector<Group*> groups;
  string fileStudents;
  string fileGroups;
  int numSt;
  int numGr;
  vector<pair<float, string>> StStat;
  vector<pair<float, string>> GrStat;
 public:
  Deanery(string, string);
  void CreateStudents();
  void CreateGroups();
  void addMarks();
  void getStatistics(string);
  void changeGroup(string, string);
  void exceptionStudent();
  void update(string);  // update info in file
  void electGhead();
  void printinfo();
};

#endif  // INCLUDE_DEANARY_H_
