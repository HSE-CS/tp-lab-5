// Copyright 2020 Osmanov Islam
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Group.h"
#include "Reader.h"

class Deanary {
 private:
  std::vector<Group*> groups;
  int number_of_groups;
  int number_of_marks = 10;
 public:
    Deanary();
  void fireStudents();
  Group* hireStudents(std::string StudentFile,
                      Group *someGroup, std::string groupId);
  void createGroups(std::string StudentsFile, std::string GroupsFile);
  void addMarksToAll();
  void moveStudent(Student* student , Group* other_group);
  void getStatistics();
  void saveStuff(std::string filePath);
  void initHeads();
  void printGroupsHeads();
  int getNumGroups();
  Group getGroup(int ind);
};


#endif  // INCLUDE_DEANARY_H_
