// Copyright 2021 Kris

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include "Group.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Group;

class Student {
 private:
     int id;
     std::string fio;
     Group *group;
     std::vector<int> marks;
 public:
     Student(int id_new, std::string fio_new);
     void addToGroup(Group *gr);
     void addmark(int mark);
     float getAveragemark();
     int isHeadOfGroup();
     std::string getFiofromId(int id);
     int getId();
     std::string getFio();
     Group* getGroup();
};

#endif // !INCLUDE_STUDENT_H_

