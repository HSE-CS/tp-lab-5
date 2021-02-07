// Copyright 2021 Ryzhova
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <vector>
#include "Group.h"

class Deanary {
  friend class Group;
  friend class Student;

 private:
  std::vector<Group *> groups;

 public:
  void create_group(std::string title, std::string spec);
  void hire_student(Student* student, std::string title);
  void add_marks_to_all();
  void get_statistics();
  void move_student(int id, std::string group);
  void init_heads();
  void fire_student(Student* student);
};

#endif  // INCLUDE_DEANARY_H_
