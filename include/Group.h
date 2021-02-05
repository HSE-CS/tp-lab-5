// Copyright 2021 Andrey Bakurskii
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"


class Deanary;
class Student;

class Group {
  friend class Deanary;

 private:
  std::string title;
  std::string spec;
  std::vector <Student*> students;
  Student* head;

  void addStudent(Student*);
  void chooseHead();
  void removeStudent(Student*);

 public:
  Group();
  explicit Group(std::string);
  explicit Group(std::string, std::string);
  Student* getStudent_byID(int id);
  Student* getStudent_byFIO(std::string);
  float getAveragemark();
  Student* getHead();
  bool containsStudent(Student*);
  bool isEmpty();
  void printGroup(bool);
  std::string getGroupAsString();
  std::string getTittle();
  std::string getSpec();
};

#endif  // INCLUDE_GROUP_H_
