// Copyright 2020 Osmanov Islam
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <iostream>
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
  void removeStudent(Student* stud);
  void addStudent(Student* stud);
  void chooseHead(Student* stud);
  friend class Deanary;
 public:
  Group(std::string title, std::string spec);
  bool containsStudent(int id);
  bool containsStudent(std::string fio);
  Student* getHead();
  Student* findStudent(int id);
  Student* findStudent(std::string fio);
  bool isEmpty();
  double getAverageMark();
  void printHead();
  int getNumStudents();
  std::string getTitle();
  std::string getSpec();
};


#endif // INCLUDE_GROUP_H_
