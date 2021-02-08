// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_DAENARY_H_
#define INCLUDE_DAENARY_H_

#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Group.h"

class Group;
class Student;

class Deanary {
    friend class Group;

 private:
    std::vector<Group*> groups;

 public:
    Deanary() {}
    void createGroups(std::ifstream file);
    void readStudents(std::ifstream file);
    void addGroup(Group* name);
    void addStudents(Student* newOne, std::string groupName);
    void addMarksToAll();
    void getStatistic();
    void moveStudents(Student* student, std::string groupName);
    void saveStaff();
    void initHeads();
    void fireStudents(Student* unluckyStudent);
    Group* findGroup(std::string name);
    Student* findStudent(std::string name);
};

#endif // INCLUDE_DAENARY_H_
