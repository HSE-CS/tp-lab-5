// Copyright 06.02.21 DenisKabanov

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <fstream>
#include <iostream>
#include "Student.h"
#include "Group.h"

class Deanary {
 private:
    std::vector<Group*> groups;
    unsigned int groupid = 0;

 public:
    explicit Deanary(std::string file);
    void createGroups(std::string file);
    void hireStudents(std::string file);
    void addMarksToAll();
    void getStatistics(std::string file);
    void moveStudents(int id, std::string title);
    void saveStaff(std::string filegroups, std::string filestudents);
    void initHeads();
    void fireStudents();
    Group* getGroup(std::string title);
    Student* getStudent(int id);
};
#endif  // INCLUDE_DEANARY_H_
