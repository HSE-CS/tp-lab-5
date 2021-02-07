// Copyright 2021 Sozinov Kirill
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include "Group.h"
#include <string>
#include <vector>

class Group;

class Student {
    friend class Deanery;
    friend class Student;
 private:
     size_t id;
     std::string fio;
     Group *group{};
     std::vector <size_t> marks;
     void addToGroup(Group *group);
     void addmark(size_t mark);
     std::string getFIO();
     unsigned getID();
     bool isHead = false;
     Group *getGroup();
 public:
    Student(unsigned id, std::string fio);
    ~Student();
    bool isHeadOfGroup();
    double getAverageMark();
};


#endif  // INCLUDE_STUDENT_H_
