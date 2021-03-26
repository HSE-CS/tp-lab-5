// Copyright 2021 by Liza

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include "Group.h"

class Group;
class Student;
class Deanary {
friend class Group;
 public:
Deanary() {}
void createGroups(std::ifstream file);
void hireStudents(std::ifstream file);
void addMarksToAll();
void getStatistics();
void moveStudents(Student* student, std::string groupName);
void addStudents(Student* newOne, std::string groupName);
void saveStaff();
void initHeads();
void fireStudents(Student* unluckyStudent);
Group* findGroup(std::string name);
Student* findStudent(std::string name);
int getStudentsNumber(std::string groupName);
void addGroup(Group* name);

 private:
std::vector<Group*> groups;
};
#endif   // INCLUDE_DEANARY_H_
