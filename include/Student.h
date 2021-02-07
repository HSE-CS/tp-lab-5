// Copyright 2021 Lab_5 TiNa
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include <string>
#include <vector>
#include "Group.h"

class Group;
class Student {
    friend class Deanary;
 private:
     int id;
     std::string fio;
     Group* group;
     std::vector<int> marks;

 public:
     Student(int id, std::string fio);
     void addToGroup(Group* group);
     void addMark(int mark);
     double getAveragemark();
     int getId();
     std::string getFio();
     Group* getGroup();
};

#endif  // INCLUDE_STUDENT_H_
