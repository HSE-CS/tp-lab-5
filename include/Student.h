// Copyright 2021 Nikolaev Ivan

#ifndef INCLUDE_STUDENT_H_ 
#define INCLUDE_STUDENT_H_
#include <iostream>
#include <string>
#include <string>
#include <vector>
#include "Group.h"

class Group;
class Deanary;

class Student {
    friend class Deanary;
    friend class Group;
 public:
     double getAveragemark();
     bool isHeadOfGroup();
     Student();
     explicit Student(std::string fio);
     Student(int id, std::string fio);
     Student(int id, std::string fio, Group* group);
     Student(int id, std::string fio, std::vector<int> marks);
     Student(int id, std::string fio, Group* group, std::vector<int> marks);
     int getId();
     std::string getFio();
 private:
     int id;
     std::string fio;
     Group* group;
     std::vector<int> marks;
     void addToGroup(Group* group);
     void addmark(int mark);
};

#endif  // INCLUDE_MYSTACK_H_