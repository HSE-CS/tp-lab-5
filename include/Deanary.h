// Copyright 2021 Bekina Svetlana
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include "Group.h"

class Group;
class Student;

class Deanary {
    friend class Student;
    friend class Group;
 public:
    Deanary();
    ~Deanary();
    void createGroup();
    void hireStudents();
    void addMarksToAll();
    void getStatistics() const;
    void moveStudents(std::string, std::string);
    void saveStaff();
    void initHeads();
    void fireStudents();
    std::vector<Group*> getgroups() const;
	
 private:
    std::vector<Group*> groups;
};
#endif  // INCLUDE_DEANARY_H_
