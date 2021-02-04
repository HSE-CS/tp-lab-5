// Copyright 2020 S. BOR
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <vector>
#include <string>
#include "Group.h"

class Group;

class Student {

 private:
  Group *group;
  int id;
  std::string fio;
  std::vector<int> marks;
  void addToGroup(Group *group);
  void addMark(int mark);
  friend class Group;
  friend class Deanary;

 public:
  Student(int id, std::string fio);
  bool isHeadOfGroup();
  double getAvarageMark();
};

#endif  // INCLUDE_STUDENT_H_
