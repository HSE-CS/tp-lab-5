// Copyright 2020 Dumarevskaya
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include "Student.h"
#include <vector>
#include <string>
class Student;
class Deanary;

class Group {
  friend class Student;
  friend class Deanary;
 private:
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* head;

 public:
  Group(std::string title, std::string spec) : title{ title }, spec{ spec } {}
  ~Group() {}
  void addStudent(Student*);
  void chooseHead(Student*);
  double getAveragemark();
  Student* getStudent(std::string);
  bool containsStudent(std::string);
  void removeStudent(Student*);
  bool isEmpty();
};

#endif  // INCLUDE_GROUP_H_
