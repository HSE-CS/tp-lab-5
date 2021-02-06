// Copyright 2021 FOM

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <vector>
#include <string>
#include <iostream>

#include "Deanary.h"
#include "Group.h"

class Group;
class Deanary;

class Student {
 private:
    int ID;
    std::string FIO;
    Group* group;
    std::vector<int> marks;
 public:
    Student(int ID, std::string FIO);
    int student_ID();
    std::string student_FIO();
    void student_group(Group* group);
    void add_mark(int mark);
    double student_mark_avarage();
    friend class Group;
    friend class Deanary;
};
#endif  // INCLUDE_STUDENT_H_
