// Copyright 2021 Bogomazov
#ifndef _INCLUDE_STUDENT_H
#define _INCLUDE_STUDENT_H
#include <vector>
#include <string>
#include "../include/Group.h"

class Student {
 private:
    int _id;
    std::string _fio;
    Group _group;
    std::vector<int> _marks;
 public:
    Student(int id, std::string fio, std::vector<int> marks, Group group):
        _id(id),
        _fio(fio),
        _group(group),
        _marks(marks) {}
    void addMark(int mark);
    float calculateMeanMark();
    bool enrollInGroup(Group group);
};
#endif  // _INCLUDE_STUDENT_H
