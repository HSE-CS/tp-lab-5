// Copyright 2020 Polina Lukicheva
#ifndef INCLUDE_STUDENTS_H_
#define INCLUDE_STUDENTS_H_

#include "string"
#include "vector"
#include "Group.h"

class Student {
  friend class Deanary;
  friend class Group;
private:
  int id;
  std::string fio;
  Group* group;
  std::vector<int> marks;
  void add2Group(Group* group);
  void addmark(int mark);
public:
  Student(int id, std::string fio);
  ~Student();
  double averageMark();
  void add2Group(Group* group);
  bool isHeadOfGroup();
  int getId();
  std::string getFio();
};
#endif  // INCLUDE_STUDENTS_H_

