// Copyright 2021 soda
#ifndef LAB_5_STUDENT_H
#define LAB_5_STUDENT_H

#include "Group.h"
#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <functional>

class Group;

class Student {
    friend class Deanery;
 private:
    int id;
    std::string fio;
    Group* group{};
    std::vector<int>marks;
    void addToGroup(Group*);
    void addmark(int);
 public:
    Student(int _id_, std::string& _fio_): id(_id_), fio(_fio_) {}
    double getAverageMark();
    bool isHeadOfGroup();
    int getId() const;
    const std::string& getName() const;
    
};

#endif  // LAB_5_STUDENT_H