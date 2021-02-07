// Copyright 2021 Bogomazov
#ifndef _INCLUDE_STUDENT_H
#define _INCLUDE_STUDENT_H
#include <vector>
#include <string>

class Group;
class Student {
 public:
    int id;
    std::string fio;
    Group *group;
    std::vector<int> marks;
    Student(int _id, std::string _fio,
            std::vector<int> _marks, Group* _group = NULL):
        id(_id),
        fio(_fio),
        group(_group),
        marks(_marks) {}
    void addMark(int mark);
    float calculateMeanMark();
    bool enrollInGroup(Group* group);
};

#endif  // _INCLUDE_STUDENT_H
