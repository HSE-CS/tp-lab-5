// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <random>
#include <string>
#include <vector>

#include "Student.h"

class Student;

class Group {
 private:
  std::string title;
  std::string spec;
  std::vector<Student *> students;
  Student *head;
  void chooseHead();
  void removeStudent(Student *);

 public:
  void AddStudent(Student *);
  Group(std::string, std::string);
  double getAverageMark();
  Student *getStudent(int);
  bool containsStudent(int);
  bool isEmpty();
  Student *getHead();
  friend class Deanary;
};

#endif  // INCLUDE_GROUP_H_
