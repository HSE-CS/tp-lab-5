// Copyright 2021 Smirnov Grigory
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <iostream>
#include <string>
#include <vector>

class Group;

class Student {
 private:
   int id;
   std::string fio;
   Group* group;
   std::vector<int> marks;

 public:
   Student(int id, std::string fio);
   int getId();
   std::string getFio();
   void addMark(int mark);
   void addToGroup(Group* new_group);
   double getAverageMark();
   bool isHeadOfGroup();
   std::string getInfo();
};
#endif  // INCLUDE_STUDENT_H_
