// Copyright 2021 soda

#ifndef LAB_5_STUDENT_H
#define LAB_5_STUDENT_H

#include "Group.h"
#include <vector>
#include <string>
#include <iostream>
#include <numeric>

class Group;

class Student {
    friend class Deanary;
private:
    int id;
    std::string fio;
    Group* group{};
    std::vector<int>marks;
    void addToGroup(Group*);
    void addmark(int);
public:
    Student(int _id_, std::string& _fio_) : id(_id_), fio(_fio_) {}
    double getAverageMark();
    bool isHeadOfGroup();
    int getId();
    const std::string& getName();

};

#endif  // LAB_5_STUDENT_H
