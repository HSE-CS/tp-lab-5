// Copyright 2021 idpas
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <iostream>
#include <string>
#include "Student.h"
#include "Deanary.h"

class Student;

class Group {
 private:
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* head;

 public:
  Group();
  explicit Group(std::string title);
  void AddStudent(Student* student);
  void ChooseHead();
  int GetAvarageMark();
  Student* GetStudent_id(int id);
  Student* GetStudent_fio(std::string fio);
  void RemoveStudent_id(int id);
  void RemoveStudent_fio(std::string fio);
};

#endif  // INCLUDE_GROUP_H_