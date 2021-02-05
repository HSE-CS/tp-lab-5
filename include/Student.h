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
  int GetId() const;
  bool isHeadOfGroup();
  void setMark(int mark);
  double getAverageMark();
  Group *GetGroup() const;
  void setGroup(Group *group);
  Student(int id, std::string fio);
  const std::string &GetFio() const;
  const std::vector<int> &GetMarks() const;
};

#endif  // INCLUDE_STUDENT_H_
