// Copyright 2021 mkhorosh
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include<vector>
#include<string>
#include"Group.h"

class Group;

class Student {
  friend class Group;
  friend class Deanary;
 private:
  std::string id;
  std::string fio;
  Group *group;
  std::vector<int> marks;

 public:
  Student(std::string id="", std::string fio="");
  double getAverageMark();
  bool isHeadOfGroup();

 private:
  void addToGroup(Group *group);
  void addMark(int mark);
};

#endif  // INCLUDE_STUDENT_H_
