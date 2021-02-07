// Copyright 2021 Bogomazov
#ifndef _INCLUDE_STUDENT_H
#define _INCLUDE_STUDENT_H
#include <vector>
#include <string>
// #include "../include/Group.h"

class Group;
class Student {
 private:
    int _id;
    std::string _fio;
    Group *_group;
    std::vector<int> _marks;
    bool _isHead;

 public:
    Student(int id, std::string fio,
            std::vector<int> marks = std::vector<int>(),
            Group* group = NULL,
            bool isHead = false):
        _id(id),
        _fio(fio),
        _group(group),
        _marks(marks),
        _isHead(isHead) {}
    void addMark(int mark);
    float calculateMeanMark();
    void enrollInGroup(Group* group);
    int getId();
    Group*  getGroup();
    void setGroup(Group *group);
    std::string getFio();
    std::vector<int> getMarks();
    void setId(int id);
    void setFio(std::string fio);
};

#endif  // _INCLUDE_STUDENT_H
