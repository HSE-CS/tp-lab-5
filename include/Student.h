// Copyright 2021
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include <string>
#include <vector>
#include "Group.h"
class Group;

class Student {

 private:
    int id;
    std::string fio;
    std::vector<int> marks;
    Group* group;
 public:
    Student(std::string fio, int id);
    void addToGroup(Group* group);
    void addMark(int mark);
    double getAverageMark();
    int getId();
    std::string getFio();
    void removeGroup();
    void setMarks(std::vector<int> marks);
    std::string getGroupTitle();
};
#endif  // INCLUDE_STUDENT_H_
