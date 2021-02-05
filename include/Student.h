// Copyright 2021 Nikita Naumov
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

#include "Group.h"

class Group;

class Student {
 public:
  Student(unsigned, std::string);
  ~Student();
  void getInfo();
  void printMarks();
  double getAverageMark();
 private:
  unsigned id;
  std::string fio;
  Group* group;
  std::vector<int> marks;
  bool isHead;
  void makeHead();
  void addMarkToStudent(int);
  void addToGroup(Group* destinationGroup);
  friend class Group;
};

#endif  // !INCLUDE_STUDENT_H_
