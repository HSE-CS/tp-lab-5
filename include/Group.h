// Copyright 2021 PaninaPolina
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

class Student;
class Dean;
class Group {
  friend class Deanery;
 private:
  std::string title;
  std::vector<Student *> students;
  int num;
  Student *head;
 public:
  explicit Group(std::string);
  Student *electHead();
  void addStudent(Student *);
  Student *searchSfio(std::string);
  Student *searchSid(int);
  float averageGroup();
  void exceptionStudent(std::string);
};

#endif  // INCLUDE_GROUP_H_
