// Copyright 2021 mkhorosh
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include<vector>
#include<string>
#include"Student.h"
#include "Deanary.h"

class Deanary;

class Student;
class Group {
  friend class Deanary;
  friend class Student;
 private:
  std::string title;
  std::string spec;
  std::vector<Student *> students;
  Student *head;

 public:
  Group(std::string title="", std::string spec="");
  double getAverageMark();
  Student *getStudent(const std::string &id);
  bool isEmpty();

 private:
  void addStudent(Student *new_student);
  void chooseHead();
  void removeStudent(const std::string &id);
};

#endif  // INCLUDE_GROUP_H_
