//  Copyright © 2021 Ksuvot. All rights reserved.

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <vector>
#include <string>
#include "Group.h"

class Group;

class Student {
  friend class Group;
  friend class Deanary;

 private:
  int id;
  Group* group;
  std::string fio;
  std::vector<int> marks;

 public:
  bool isHeadOfGroup();
  void setMark(int mark);
  double getAverageMark();
  void setGroup(Group *group);
  Student(int id, std::string fio);
};

#endif  // INCLUDE_STUDENT_H_
