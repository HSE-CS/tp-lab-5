//  Copyright 2020 Baklanov
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include "Group.h"
#include "Student.h"
#include <iostream>
#include <vector>
#include <string>

class Group;

class Student;

class Deanary {
 private:
std::vector<Group> groups;

 public:
void createGroups(std::string path);
void hireStudents(std::string path);
void addMarksToAll();
double getStatistics();
void moveStudents();
void saveStaff(std::string pathGroup, std::string pathStudent);
void initHeads();
void fireStudents(int number);
Group* getGroup(int number) {
return &groups[number];
}
};

#endif // INCLUDE_DEANARY_H_
