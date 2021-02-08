// Copyright 2021 Ryzhova
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <vector>
#include <string>

class Group;

class Student {
  friend class Group;
  friend class Deanary;

 private:
  int id;
  std::string fio;
  Group* group;
  std::vector<int> marks;
  void add_to_group(Group*);
  void add_mark(int);

 public:
  Student(int id, std::string fio, Group* group = nullptr);
  bool is_head_of_group();
  double get_average_mark();
  int get_id();
  std::string get_fio();
};

#endif  // INCLUDE_STUDENT_H_
