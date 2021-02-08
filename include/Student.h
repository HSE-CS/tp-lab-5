// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <vector>
#include <string>
#include "Group.h"

class Group;

class Student {
    friend class Deanary;
    friend class Group;

 private:
    std::string id;
    std::string fio;
    Group* group;
    std::vector <uint64_t> marks;

 public:
    Student() {}
    Student(std::string ID, std::string FIO);
    void groupIs(Group* G);
    void addMark(uint64_t mark);
    int averageMark();
    std::string getGroup();
};


#endif   // INCLUDE_STUDENT_H_
