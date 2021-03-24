// Copyright 2021 Tyulin Igor

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include "Group.h"
#include <string>
#include <vector>

class Group;
class Deanary;

class Student {
    friend class Group;
    friend class Deanary;
 private:
    int id;
    std::string fio;
    Group* group;
    std::vector<int> marks;
 public:
    Student(int id, std::string fio);
    int stud_id();
    std::string stud_fio();
    void group_add(Group* group);
    void mark_add(int mark);
    double average_mark();
};

#endif  // INCLUDE_STUDENT_H_
