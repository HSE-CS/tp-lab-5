// Copyright 2020 Uskova
#ifndef INCLUDE_STUDENT_H_
#define  INCLUDE_STUDENT_H_
#include <string>
#include <vector>
#include "Group.h"

class Group;

class Student {
    friend class Group;
    friend class Deanary;
 private:
     int id;
     std::string fio;
     Group *group;
     std::vector <int> marks;
     void addMark(int mark);
     void addToGroup(Group* group);
 public:
     Student();
     explicit Student(int, std::string);
     float getAverageMark();
     bool isHeadOfGroup();
     std::string getFio();
};

#endif  // INCLUDE_STUDENT_H_
