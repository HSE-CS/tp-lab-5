// Copyright 2021 Bugrov
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <iostream>
#include <string>
#include <vector>
#include "Deanary.h"
#include "Student.h"

class Student;
class Group {
  friend class Deanary;
 private:
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* headman{};
 public:
  explicit Group(std::string title, std::string spec);
  void choose_headman();
  void add_student(Student* student);
  void remove_student(Student* student);
  bool find_student(int id);
  bool find_student(const std::string& name);
  double average_mark();
  std::string get_title();
  std::string get_spec();
};

#endif  // INCLUDE_GROUP_H_
