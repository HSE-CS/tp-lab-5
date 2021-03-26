// Copyright 2021 
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
  void Add2Group(Group *);
  void AddMark(int);

 public:
   explicit Student(int, std::string);
   bool isleadOfGroup();
   double getAverageMark();
   int getId();
   std::string getFio();
   friend class Deanary;
   friend class Group;
};

#endif  // INCLUDE_STUDENT_H_