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
  Group(std::string, std::string);
  void AddStudent(Student *);
  void chooseHead();
  void removeStudent(Student *);

 public:
  double getAverageMark();
  Student *getStudent(int);
  bool containsStudent(Student *);
  bool isEmpty();
  Student *getHead();
  friend class Deanary;
};

#endif  // INCLUDE_GROUP_H_
