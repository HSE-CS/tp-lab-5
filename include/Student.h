// Copyright 2020 GHA Test Team
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include <string>
#include <vector>
#include <iostream>
#include "Group.h"


class Group;

class Student {
  friend class Deanary;
 private:
  int id;
  std::string fio;
  Group* group;
  std::vector <int> marks;
  void addToGroup(Group*);
  void addMark(int);
  void printMarks();
  void setGroup(Group*);

 public:
  Student();
  explicit Student(int, std::string);
  explicit Student(Student*);
  float getAverageMark() const;
  bool isHeadOfGroup() const;
  int getId() const;
  std::string getFio() const;
};
#endif  // INCLUDE_STUDENT_H_
