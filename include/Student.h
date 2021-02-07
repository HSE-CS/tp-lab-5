// Copyright 2021 Kartseva Masha 
#pragma once
#define STUDENT_H
#ifdef STUDENT_H
#include <iostream>
#include <string>
#include <vector>
#include "Group.h"

class Group;
class Student
{
public:
    Student(std::string name, unsigned int id);
    unsigned int AverageMark() const;
    void addMark(unsigned int mark);
    std::string getName() const;
    std::string getGroup() const;
    unsigned int getId() const;
    void setGroup(Group* group);
private:
    int id;
    std::string name;
    Group* group;
    std::vector<unsigned int> marks;
};

#endif // STUDENT_H
