// Copyright 2021 GN
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include "Group.h"
#include <iostream>
#include <string>
#include <vector>
class Group;
class Student {
    friend class Deanary;
 private:
    int id;
    std::string fio;
    Group* group;
    std::vector<int> marks;

 public:
    explicit Student(int id_, std::string fio_) {
        id = id_;
        fio = fio_;
    }
    double avMark();
    void addMark(int m_);
    int getId();
    std::string getName();
};
#endif  //  INCLUDE_STUDENT_H_
