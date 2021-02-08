// Copyright 2020 Polina Lukicheva
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <string>
#include <vector>
#include "Student.h"

class Student;

class Group {
 private:
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* head;
  void chooseHead();
  void removeStudent(Student *);
 public:
  Group();
  explicit Group(const std::string);
  explicit Group(const std::string, const std::string);
  ~Group();
  bool isEmpty();
  void addStudent(Student*);
  Student *getStudent(int);
  Student *getHead();
  bool containsStudent(Student *);
  float getAverageMark();
  friend class Deanary;
};
#endif  // INCLUDE_GROUP_H_

