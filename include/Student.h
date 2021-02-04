// Copyright 2021 Bodrov Egor
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <vector>
#include <string>

#include "Group.h"

class Group;

class Student {
    friend class Group;
    friend class Deanary;
 private:
     int id;
     std::string fio;
     Group* group = nullptr;
     std::vector <int> marks;

 public:
     explicit Student(int id_, const std::string& name);
     double getAveragemark();
     int get_id();
     std::string& get_name();
     bool isHeadOfGroup();
     void addToGroup(Group* group_);
     void addmark(int mark);
};

#endif  // INCLUDE_STUDENT_H_
