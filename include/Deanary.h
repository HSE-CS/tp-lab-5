// Copyright 2021 Bodrov Egor
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>

#include "Group.h"

class Group;

class Deanary {
 private:
    std::vector <Group*> groups;
    std::vector <Student*> students;

 public:
     Deanary() = default;
     void hireStudents(const std::string& input);
     void createGroups(const std::string& input);
     void addMarksToAll();
     void getStatistics(const std::string& output);
     void moveStudents(Student* student, const std::string& title);
     void saveStaff(const std::string& students_file, 
     const std::string& groups_file);
     void initHeads();
     void fireStudents();
     void chooseGroup(Student* student);
};

#endif  // INCLUDE_DEANARY_H_
