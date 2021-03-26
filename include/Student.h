// Copyright 2021 Bekina Svetlana
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include "Group.h"

class Group;

class Student {
 public:
    Student();
    explicit Student(std::string, std::string, Group*);
    ~Student();
    void addToGroup(Group*);
    void addmark(int mark);
    double getAveragemark() const;
    bool isHeadOfGroup() const;
    std::string getId() const;
    std::string getFio() const;
    std::vector<int> getmarks() const;

 private:
    std::string id;
    std::string fio;
    Group* group;
    std::vector<int> marks;
};
#endif  // INCLUDE_STUDENT_H_

