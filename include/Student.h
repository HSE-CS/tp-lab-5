// Copyright 2021 Bugrov
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include "Group.h"
#include <vector>
#include <string>
#include <iostream>

class Group;
class Student {
  friend class Group;
  friend class Deanary;
 private:
  int id;
  std::string name;
  Group* group;
  std::vector<int> marks;
 public:
  explicit Student(int id, std::string name);
  void add_to_group(Group* group);
  void add_mark(int mark);
  double average_mark();
  [[nodiscard]] int get_id() const;
  std::string get_name();
};

#endif  // INCLUDE_STUDENT_H_
