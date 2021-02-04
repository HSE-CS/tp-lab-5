//Copyright 2021 Nikita Naumov
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>
#include "Group.h"

class Group;

class Student {
 public:
  Student(unsigned, std::string);
  ~Student();
  void addToGroup(Group* destinationGroup);
  void addMarkToStudent(int);
  void getInfo();
  void printMarks();
  double getAverageMark();

 private:
  unsigned id;
  std::string fio;
  Group* group;
  std::vector<int> marks;
};


#endif  // !INCLUDE_STUDENT_H_
