// Copyright 2021 Galex

#ifndef TP_LAB_5_INCLUDE_GROUP_H_
#define TP_LAB_5_INCLUDE_GROUP_H_
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
#endif  // TP_LAB_5_INCLUDE_GROUP_H_
