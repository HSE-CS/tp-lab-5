// Copyright 2021 Grachev Alexander

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "../include/Student.h"
#include "../include/Group.h"

class Deanary {
 private:
    std::vector<Group> groups;

 public:
    void addStudents(std::fstream&);
    std::vector<Group> &getGroups();
    void addRandMarks();
    void getStatistic();
    void moveStudent(Student student, Group newGroup);
    void expelStudents(std::fstream&);
    void saveStaff();
    void initLeaders();
    void info();
};

#endif  // INCLUDE_DEANARY_H_
