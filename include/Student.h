// Copyright 2021 Tyulin Igor

#ifndef TP_LAB_5_STUDENT_H
#define TP_LAB_5_STUDENT_H

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

#endif //TP_LAB_5_STUDENT_H
