// Copyright 2021 PaninaPolina
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;
class Student;
class Dean;
class Group {
  friend class Deanery;
 private:
  string title;
  vector<Student *> students;
  int num;
  Student *head;
 public:
  Group(string);
  Student *electHead();
  void addStudent(Student *);
  Student *searchSfio(string);
  Student *searchSid(int);
  float averageGroup();
  void exceptionStudent(string);
};

#endif  // INCLUDE_GROUP_H_
