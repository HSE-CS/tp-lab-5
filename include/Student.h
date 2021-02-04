// Copyright 2021 soda

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <Group.h>
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

#endif  // INCLUDE_STUDENT_H_
