// Copyright 2021 Pavlova D.

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include "Group.h"
#include <vector>
#include <string>

class Group;

class Student {
  friend class Group;

 private:
  int id;
  std::string fio;
  std::vector<int> marks;

 public:
  Group *group_{};
  Student(int id_, std::string &fio_) : id(id_), fio(fio_) {}
  void addToGroup(Group *_group);
  void addMark(int mark);
  double getAverageMark();
  bool isHeadOfGroup() const;
  int getID() { return id; }
  std::string getFIO() { return fio; }
};
#endif  // INCLUDE_STUDENT_H_
