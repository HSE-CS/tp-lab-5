// Copyright 06.02.21 DenisKabanov

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>
#include "Group.h"

class Group;

class Student {
 private:
    unsigned int id;
    std::string fio;
    Group* group = nullptr;
    std::vector<int> marks;

 public:
    Student(unsigned int newid, std::string newfio);
    void addToGroup(Group* togroup);
    void addMark(int newmark);
    float getAveragemark();
    int getId();
    std::string getFio();
    Group* getGroup();
    bool isHeadOfGroup();
};

#endif  // INCLUDE_STUDENT_H_
