// Copyright 2021 
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <random>
#include <string>
#include <vector>

#include "Student.h"

class Student;

class Group {
 private:
  std::string name;
  std::string spec;
  std::vector<Student *> students;
  Student *lead;
  Group(std::string, std::string);
  void AddStudent(Student *);
  void chooselead();
  void removeStudent(Student *);

 public:
  Group(std::string, std::string);
  double getAverageMark();
  Student *getStudent(int);
  void AddStudent(Student *);
  bool containsStudent(int);
  bool isEmpty();
  Student *getlead();
  friend class Deanary;
};

#endif  // INCLUDE_GROUP_H_