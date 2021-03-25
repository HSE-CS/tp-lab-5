// Copyright 2021 by Liza

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <vector>
#include <string>
#include "Group.h"

class Group;

class Student {
friend class Deanary;
friend class Group;

 public:
Student() {}
Student(std::string ID, std::string FIO);
void addToGroup(Group* G);
void addmark(int mark);
int getAveragemark();
std::string getGroup();

 private:
std::string id;
std::string fio;
Group* group;
std::vector<int> marks;};
#endif   // INCLUDE_STUDENT_H_
