// Copyright 2021 Drobot E.D.

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
  std::string fio;
  Group* group;
  std::vector<int> marks;

 public:
  void add_to_group(Group* group);
  void add_mark(int mark);
  Student(int id, std::string fio);
  double average_mark();
  int get_id();
  std::string get_fio();

};
#endif // INCLUDE_STUDENT_H_
