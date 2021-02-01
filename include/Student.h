// Copyright 2021 Kuznetsov Mikhail
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <vector>
#include <string>
#include "Group.h"

class Student {
 private:
    unsigned int id;
    std::string fio;
    Group* group = nullptr;
    std::vector <int> marks;

 public:
    Student(unsigned int _id, std::string _fio);
    void addToGroup(Group *_group);
    void addMark(int _mark);
    float getAveragemark();
    unsigned int getId();
    std::string getFio();
    //bool isHeadOfGroup();
};

#endif  // INCLUDE_STUDENT_H_

