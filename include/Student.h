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
  void AddToGroup(Group *);
  void AddMark(int);

 public:
  explicit Student(int, std::string);
  bool isHeadOfGroup();
  double getAverageMark();
  int getId();
  std::string getFio();
  friend class Deanary;
};

#endif  // INCLUDE_STUDENT_H_
