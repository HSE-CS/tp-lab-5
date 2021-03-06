//
//  include:Deanary.h
//  tp-lab-5
//
//  Created by Anastasiya Rogozyan on 03.03.2021.
//  Copyright © 2021 Anastasiya Rogozyan. All rights reserved.
//

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
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
     std::vector<float> getStatistics(bool byGroup = true);
     void moveStudents(Student *student, Group *newGroup);
     void fireStudents();
     void addMarksToAll();
};

#endif  // INCLUDE_DEANARY_H_
