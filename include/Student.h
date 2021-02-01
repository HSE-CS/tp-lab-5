// Copyright 2021 Khoroshavina Ekaterina
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <iostream>
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
     Group* group;
     std::vector<int> marks;
     void addMark(int mark);
     void addToGroup(Group* group);
 public:
     Student(int id, std::string FIO);
     ~Student();
     int getId() const;
     const std::string& getFIO() const;
     Group* getGroup() const;
     int getAverageMark();
     bool isHeadOfGroup();
};

#endif  // INCLUDE_STUDENT_H_
