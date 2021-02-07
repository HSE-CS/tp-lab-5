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
      explicit Deanery(std::vector<Group*> groups): _groups(groups) {}
      std::vector<Student*> createStudentsFromFile(std::string fileName);
      std::vector<Group*> createGroupsFromFile(std::string fileName);
      bool saveData(std::string fileName);
};

#endif  // _INCLUDE_DEANERY_H
