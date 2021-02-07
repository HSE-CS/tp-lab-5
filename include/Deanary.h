// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <fstream>
#include <string>
#include <vector>

#include "Group.h"

class Student;
class Group;

class Deanary {
 private:
  std::vector<Group *> groups;
  unsigned int id;

 public:
  Deanary();
  void createGroups(std::string _filename);
  void hireStudents(std::string _filename);
  void addMarksToAll();
  void getStatistics(std::string _filename);
  void MoveStudents(unsigned int, std::string title);
  void saveStaff(std::string, std::string);
  void initHeads();
  void fireStudents();
};

#endif  // INCLUDE_DEANARY_H_
