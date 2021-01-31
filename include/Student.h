// Copyright 2020 Khoroshavina Ekaterina
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <iostream>
#include <string>
#include <vector>
#include "Group.h"

class Group;

class Student {
 private:
     int id;
     std::string fio;
     Group* group;
     std::vector<int> marks;
     void addMark(int mark);
     void addToGroup(Group* group);
 public:
     int getId() const;
     std::string& getFIO() const;
     Group* getGroup() const;
     int getAverageMark();
     bool isHeadOfGroup();
};


#endif  // INCLUDE_STUDENT_H_
