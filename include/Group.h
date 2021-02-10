// Copyright 2021 Tatsenko Alexey
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

class Student;
class Deanary;

class Group {
 private:
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* head;

 public:
  friend Student;
  friend Deanary;
  Group(std::string name, std::string spec)
           : title(name), spec(spec), head(nullptr) {}
  void AddStudent(Student* student);
  void ChooseHeader(Student* student);
  Student* GetStudent(std::string fi);
  // Student* GetStudent(int id);
  double GetAvarageEval();
  void RemoveStudent(Student* student);
  std::string GetHeader();
  std::string GetLastStudents();
  std::string GetTitle();
  std::string GetSpec();
};
