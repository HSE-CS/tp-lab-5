// Copyright 2021 Drobot E.D.

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <iostream>
#include <string>
#include <vector>

#include "Group.h"
#include "Student.h"

class Group;
class Student;

class Deanary {
 private:
  std::vector<Group> groups;
  std::vector<Student> Students;
 public:
  void add_student(Student* student, std::string spec);
  void add_group(Group group);
  void students_from_file();
  void groups_from_file();
  void distribution_of_students();
  void add_marks();
  double get_statistic_students(std::string fio);
  double get_statistic_groups(std::string spec);
  void student_transfer(std::string fio, std::string spec);
  void deduction_student(std::string fio);
  void save_to_file();
  void choice_head();
  void print();
};

#endif  // INCLUDE_DEANARY_H_
