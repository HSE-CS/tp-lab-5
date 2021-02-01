// Copyright 2020 Dmitry Vargin
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>

#include "Group.h"

class Group;

class Student {
private:
    unsigned int id;
    std::string fio;
    Group *group;
    std::vector<int> marks;
    static unsigned int last_student_id;
  public:
    Student(std::string fio);
    Student(int id, std::string fio);
    Student(int id, std::string fio, Group *group);

    unsigned int getId() const;
    std::string getFio();
    Group* getGroup();
    std::vector<int> getMarks();
    static unsigned int getLastId();

    void addToGroup(Group *pgroup);
    void addMark(int mark);
    double getAveragemark();
    bool isHeadOfGroup();

    std::string marksToString();
};

#endif  //  INCLUDE_STUDENT_H_
