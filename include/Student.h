// Copyright 2021 PaninaPolina
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include <string>
#include <vector>
#include <iostream>
#include "Group.h"

using namespace std;

class Group;

class Student {
  friend class Group;  
  friend class Deanery;
 private:
  int id;
  string fio;
  Group* group;
  vector<int> marks;
  int num;
 public:
  Student(int, string);
  void enterGroup(Group*); 
  void addMark(int);
  float averageMark();
};

#endif  // INCLUDE_STUDENT_H_
