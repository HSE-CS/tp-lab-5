// Copyright 2021 KarMashanova
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include "Group.h"
#include <iostream>
#include <string>
#include <vector>
class Group;
class Student {
  friend class Deanery;
 public:
 explicit Student(int id_, std::string fio_) { 
  id = id_;
  fio = fio_;
 }
 void addToGroup(Group* _group);
 void addmark(int mark);
 double Getaveragemark();
 bool isHeadOfGroup();
 int Getid();
 std::string Getname();

private:
 int id;
 std::string fio;
 Group *group;
 std::vector<int>marks;
};

#endif  // INCLUDE_STUDENT_H_
