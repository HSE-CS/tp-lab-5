// Copyright 2021 Pavlova D.

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include "Group.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <utility>

class Deanary {
  friend class Group;

 public:
  std::vector<Group *> groups;
  void createGroups();
  void hireStudents();
  void addMarksToAll(int count);
  void getStatistics();
  void moveStudents(int _id, const std::string &title);
  void saveStaff();
  void initHeads();
  void fireStudents(int _id);
  void fireStudents();
};
#endif  // INCLUDE_DEANARY_H_
