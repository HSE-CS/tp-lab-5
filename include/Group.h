// Copyright 2021 Artem Danyaev
#pragma once
#include "Student.h"
#include <string>
#include <vector>
class Student;
class Group {
  friend class Deanary;
  friend class Student;

 private:
  std::string title;
  std::string spec;
  std::vector<Student *> students;
  Student *head = nullptr;
  void addStudent(Student *student);
  void chooseHead(unsigned int id);
  void removeStudent(unsigned int id);

 public:
  explicit Group(std::string &t, std::string &s);
  std::string getTitle();
  std::string getSpec();
  Student *getStudentByFio(std::string fio);
  float getAverageMark();
  Student *getStudentById(unsigned int id);
  Student *getStudentByFio(std::string &f);
  bool containsStudentById(unsigned int id);
  bool containsStudentByFio(std::string f);
  bool isEmpty();
};
