// Copyright 2020 Dumarevskaya
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>
#include <iostream>

#include "Group.h"

typedef unsigned short us;
class Group;

class Student {
private:
  std::string id;
  std::string fio;
  Group* group;
  std::vector<us> marks;
  friend class Group;
  friend class Deanary;
public:
  Student(std::string id, std::string fio) : id{ id }, fio{ fio } {
    group = nullptr;
  };
  ~Student() {};
  void addToGroup(Group*);
  void addmark(us);
  double getAveragemark();
  bool isHeadGroup();
};

#endif // INCLUDE_STUDENT_H_
