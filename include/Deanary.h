// Copyright 2021 Pavlova D.

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include "Group.h"
#include <vector>

class Deanary {
  friend class Group;

private:
  std::vector<Group *> groups;

public:
  void createGroups();
  void hireStudents();
  void addMarksToAll(int count);
  void getStatistics();
  void moveStudents(int _id, std::string &title);
  void saveStaff();
  void initHeads();
  void fireStudents(int _id);
  void fireStudents();
};
#endif // INCLUDE_DEANARY_H_
