// Copyright 2021 Artem Danyaev
#pragma once
#include "Group.h"
#include <string>
#include <vector>
class Group;
class Student {
  friend class Group;
  friend class Deanary;

 private:
  unsigned int id;
  std::string fio;
  Group *group;
  std::vector<unsigned int> marks;
  void addToGroup(Group *gr);

 public:
  explicit Student(unsigned int i, const std::string &f);
  void addMark(unsigned int mark);
  float getAverageMark();
  bool isHeadOfGroup();
  unsigned int getId();
  std::string getFio();
};
