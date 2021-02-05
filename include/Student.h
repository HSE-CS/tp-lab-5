//  Copyright 2020 Baklanov
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include "Group.h"
#include "Deanary.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <string>

class Group;

class Student {
 private:
int id = -1;
std::string fio;
Group *group;
std::vector<int> marks;
std::string intel = "";
void addToGroup(Group& A);
bool isHead = 0;

 public:
Student(int num, std::string fi, Group* gr, int intellect);
Student(int num, std::string fi);
double getAvearagemark();
void addmark(int mark);
std::string getFio() {
return fio;
}
bool isHeadOfGroup();
int getId() {
return id;
}
friend class Deanary;
friend class Group;
};

#endif  // INCLUDE_STUDENT_H_
