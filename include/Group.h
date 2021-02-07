// Copyright 2021 Galex

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <string>
#include <vector>
#include "../include/Student.h"

class Group {
 private:
  std::string name;
  std::string spec;
  std::vector<Student *> students;
  Student *head;

 public:
  Group(std::string name, std::string spec);
  void addStudent(Student *student);
  void removeStudent(Student *student);
  void chooseHead(Student *student);
  double getAverage();
  Student *getStudent(unsigned int id);
  bool containsStudent(unsigned int id);
  bool isEmpty();
  bool isHeadChoosen();
  int getNumOfStudents();
  Student* getStudentByIndex(int i);
  std::string getName();
  Student* getHead();
};
#endif  // INCLUDE_GROUP_H_
