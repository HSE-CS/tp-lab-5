// Copyright 2021 KarMashanova
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <iostream>
#include <string>
#include "Student.h"

class Student;
class Group {
  friend class Deanary;
 public:
  std::vector<Student*> students;
  Group(const std::string Title_, const std::string Spec_) {
    Title = Title_;
    Spec = Spec_;
  }
  void addStudent(Student* student);
  void choseHead();
  double getAveragemark();
  Student& getStudent(int, std::string&);
  int containsStudent(Student&);
  void removeStudent();
  bool isEmpty();


 private:
  std::string Title();
  std::string Spec();
  std::vector<Student*>* students;
  Student* head;
};
#endif  // INCLUDE_GROUP_H_