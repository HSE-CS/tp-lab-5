// Copyright 2020 Polina Lukicheva
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include "string"
#include "vector"
#include "Group.h"

class Group;

class Student {
  friend class Group;
  friend class Deanary;
 private:
  int id;
  std::string fio;
  Group* group;
  std::vector<int> marks;
  void add2Group(Group* group);
  void addmark(int mark);
 public:
  Student();
  explicit Student(int id, const std::string fio);
  ~Student();
  double averageMark();
  bool isHeadOfGroup();
  int getId();
  std::string getFio();
};
#endif  // INCLUDE_STUDENT_H_

