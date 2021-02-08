// Copyright 2020 Polina Lukicheva
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include "Group.h"
#include "vector"
#include "string"
#include "fstream"
#include "iostream"
#include "cstdlib"

class Deanary {
 private:
  std::vector<Group*> groups;
  int id;
 public:
  Deanary();
  void createGroups(std::string file);
  void hireStudents(std::string file);
  void addMarksToAll();
  void getStatistics(std::string file);
  void moveStudents(Student*, Group*);
  void saveStaff(std::string, std::string);
  void initHeads();
  void fireStudents();
};
#endif  // INCLUDE_DEANARY_H_

