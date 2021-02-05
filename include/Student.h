//  Copyright 2020 Baklanov

#ifndef INCLUDE_Student_
#define INCLUDE_Student_

#include "Group.h"
#include "Deanary.h"
#include <iostream>
#include <vector>

class Group;

class Student {
 private:
  int id = -1;
  std::string fio;
  Group *group;
  std::vector<int> marks;
  void addToGroup(Group& A);
  bool isHead = 0;

 public:
  Student(int num, std::string fi, Group* gr);
  Student(int num, std::string fi);
  double getAvearagemark();
  void addmark(int mark);
  std::string getFio() {
  return fio;
  }
  bool isHeadOfGroup();
  int getId() {
  return id;
  }
  friend class Deanary;
  friend class Group;
};

#endif
