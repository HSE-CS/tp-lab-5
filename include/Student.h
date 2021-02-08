// Copyright 2021 Shatilov Victor

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include <string>
#include <vector>
#include "Group.h"

class Group;
class Student {
    friend class Group;
    friend class Deanary;

 private:
    int id;
    std::string fio;
    std::vector<int> marks;
    Group *group;

 public:
    explicit Student(int id, std::string fio);
    void addToGroup(Group *group);
    void rate(int mark);
    float getAverageMark();
    int getId();
    std::string getFio();
};


#endif  // INCLUDE_STUDENT_H_
