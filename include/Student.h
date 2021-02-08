// Copyright 2021 idpas
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include <iostream>
#include <string>
#include <vector>
#include "Group.h"
#include "Deanary.h"

class Group;

class Student {
 private:
  int id;
  std::string fio;
  Group* group;
  std::vector<int> marks;
 
 public:
  Student();
  explicit Student(int id, std::string fio);
  void AddToGroup(Group* group);
  void AddMark(int mark);
  float GetAverageMark();
  bool IsHeadOfGroup();

  int get_id();
  std::string get_fio();
};
#endif  // INCLUDE_STUDENT_H_