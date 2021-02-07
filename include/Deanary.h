// Copyright 2021 Schenikova
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
// #include <chrono>
#include "Group.h"

class Student;

class Group;

class Deanary {
 private:
  std::vector <Group*> groups;
  int randomId();
  unsigned int id = randomId();
 public:
  explicit Deanary(std::string filename);
  void createGroups(std::string filename);
  void hireStudents(std::string filename);
  void addMarksToAll();
  void getStatistics(std::string filename);
  void moveStudents(int id, std::string title);
  void saveStaff(std::string filename_groups, std::string filename_students);
  void initHeads();
  void fireStudents();
  void printAllInfo();
  friend class Group;
  friend class Student;
};

#endif  // INCLUDE_DEANARY_H_
