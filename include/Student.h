// Copyright 2021 Schenikova
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>
#include <iostream>

#include "Group.h"

class Group;

class Student {
  friend class Group;
private:
  int id;
  std::string fio;
  Group* group;
  std::vector <int> marks;
public:
  void addMark(int);
  void addToGroup(Group*);
  Student(unsigned int id, std::string fio);
  Group* getGroup();
  bool isHeadOfGroup();
  float getAveragemark();
  int getId();
  std::string getfio();
};

#endif // INCLUDE_STUDENT_H_