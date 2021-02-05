// Copyright 2021 Nikita Naumov
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include "Student.h"

class Student;

class Group {
 public:
  Group(std::string title);
  ~Group();
  void addStudentToGroup(Student*);
  void setHead();
  std::string getTitle();
  bool findStudentByID(unsigned id);
  bool findStudentByFIO(std::string fio);
  double getAverageGroupMark();
  void fireStudentFromGroup();

 private:
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* head;
};

#endif  // !INCLUDE_GROUP_H_
