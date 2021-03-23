// Copyright 2021 Vadukk

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <vector>
#include "Group.h"
#include "Student.h"

#include <fstream>
#include <sstream>
#include <iostream>

class Deanary {
 private:
     std::vector<Group> groups;
 public:
     void createGroups(const std::string& filename);
     void AddGroup(std::string titl, std::string spec);
     void printGroups();
     void hireStudents(const std::string& filename);
     void addMarksToAll();
     std::vector<float> getStatistics();
     void moveStudents(Student* st1, Group* gr2);
     void saveStaff(const std::string &filename);
     void initHeads();
     Group getLastGroup();
     void fireStudents();
};

#endif  // INCLUDE_DEANARY_H_
