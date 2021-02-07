// Copyright 2021 Kuznetsov Mikhail
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
    std::vector <Group*> groups;
    unsigned int curr_id;
 public:
    explicit Deanary(std::string filename);
    void createGroups(std::string filename);
    void hireStudents(std::string filename);
    void addMarksToAll();
    void getStatistics(std::string filename);
    void moveStudents(unsigned int id, std::string title);
    void saveStaff(std::string filename_groups, std::string filename_students);
    void initHeads();
    void fireStudents();
    Group* getGroup(std::string title);
    Student* getStudent(unsigned int id);
    void printData();
};
#endif  // INCLUDE_DEANARY_H_

