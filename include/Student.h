// Copyright 2020 Dmitry Vargin
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
    Group *group;
    std::vector<int> marks;
  public:
    Student(int id, std::string fio);

    int getId() const;
    std::string getFio();
    Group* getGroup();
    std::vector<int> getMarks();

    void addToGroup(Group *pgroup);
    void addMark(int mark);
    double getAveragemark();
    bool isHeadOfGroup();
};

#endif  //  INCLUDE_STUDENT_H_
