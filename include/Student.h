// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>

#include "Group.h"

class Group;

class Student {
 private:
  int id;
  std::string fio;
  std::vector<int> marks;
  Group *group;
  explicit Student(int, std::string);
  void AddToGroup(Group *);
  void AddMark(int);

 public:
  bool isHeadOfGroup();
  double getAverageMark();
  int getId();
  std::string getFio();
  friend class Deanary;
};

#endif  // INCLUDE_STUDENT_H_
