// Copyright 2021 Nikolaev Ivan

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include <map>
#include <iostream>
#include <vector>
#include "Group.h"

class Group;

class Deanary {
    friend class Group;
    friend class Student;
 public:
     Deanary();
     void createGroups(std::string title, std::string spec);
     void hireStudents(std::string title, Student* student);
     void addMarksToAll();
     std::map<int, double> getStatistics();
     std::map<int, double> getStatistics(Group *group);
     void printStatistics(std::map<int, double> list);
     void moveStudents(Group* from, Group* to, Student* student);
     void saveStaff();
     void initHeads(Group* group);
     void fireStudents(Student* student);
     void readFile();
     Group* findGroup(std::string title);
     Student* findStudent(int id);
 private:
    std::vector<Group*> groups;
    int IdCounter = 0;
};

#endif  // INCLUDE_DEANARY_H_