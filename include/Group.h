// Copyright 2021 Drobot E.D.

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
  Student* head;

  void add_student(Student* student);
  void choice_head();
  void remove_student(Student* student);

 public:
  Group(std::string title, std::string spec);
  bool find_student(int id);
  bool find_student(std::string fio);
  double avarage_mark();
  std::string get_title();
  std::string get_spec();
};


#endif  // INCLUDE_GROUP_H_
