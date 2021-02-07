// Copyright 2021 Bogomazov
#ifndef _INCLUDE_DEANERY_H
#define _INCLUDE_DEANERY_H
#include <iostream>
#include <vector>
#include <string>
#include "../include/Student.h"
#include "../include/Group.h"

class Deanery {
 private:
      std::vector<Group*> _groups;
 public:
     explicit Deanery(
          std::vector<Group*> groups = std::vector<Group*>()):
          _groups(groups) {}
     std::vector<Student*> createStudentsFromFile(std::string fileName);
     std::vector<Group*> createGroupsFromFile(std::string fileName);
     bool saveData(std::string fileName);
     std::vector<Group*> getGroups();
     void setGroups(std::vector<Group*> groups);
     void printInfo();
     std::vector<float> getStatistics(bool byGroup);
     void moveStudents(Student *student, Group *newGroup);
     void fireStudents();
     void addMarksToAll();
};

#endif  // _INCLUDE_DEANERY_H
