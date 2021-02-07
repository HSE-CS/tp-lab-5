// Copyright 2021 alexgiving

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
  void add_student(Student* student, const std::string& spec);
  void add_group(const Group& group);
  void students_from_file();
  void groups_from_file();
  void distribution_of_students();
  void add_marks();
  double get_statistic_students(const std::string& name);
  double get_statistic_groups(const std::string& spec);
  void move_student(const std::string& _name, const std::string& _spec);
  void student_expulsion(const std::string& _name);
  void save_to_file();
  void choice_headman();
  void print();
};

#endif  // INCLUDE_DEANARY_H_
