// Copyright 2021 PaninaPolina
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include <string>
#include <vector>
#include <iostream>
#include "Group.h"

class Group;

class Student {
  friend class Group;  
  friend class Deanery;
 private:
  int id;
  std::string fio;
  Group* group;
  std::vector<int> marks;
  int num;
 public:
  Student(int, std::string);
  void enterGroup(Group*); 
  void addMark(int);
  float averageMark();
};

#endif  // INCLUDE_STUDENT_H_
