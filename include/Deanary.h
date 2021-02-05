// Copyright 2021 Andrey Bakurskii

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include "Student.h"
#include "Group.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Deanary {
 private:
  std::vector<Group*> groups;
  std::vector<Student*> students;

 public:
  Deanary() {}
  void createGroups(std::string);
  void hireStudents(std::string);
  void addMarksToAll();
  void getStatistics();
  void moveStudents(Student*, Group*);
  void saveStaff(std::string);
  void initHeads();
  void fireStudents(float);
  // test
  void printStudents();
  void printGroups();
};

#endif  // INCLUDE_DEANARY_H_
