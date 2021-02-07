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
  void setHead(Student* newHead);
  std::string getTitle();
  bool findStudentByID(unsigned id);
  bool findStudentByFIO(std::string fio);
  double getAverageGroupMark();
  void fireStudentFromGroup(unsigned);
  void printInfoAboutGroup();
 private:
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* head;
  friend class Deanary;
};

#endif  // !INCLUDE_GROUP_H_
