// Copyright 2020 Stanislav Stoianov

#ifndef  INCLUDE_STUDENT_H_
#define  INCLUDE_STUDENT_H_

#include <string>
#include <vector>
#include "Group.h"

class Group;

class Student {
 private:
  int id;
  std::string fullname;
  Group *group;
  std::vector<int16_t> marks;

 public:
  Student(int id, std::string fullname);
  ~Student();
  void addToGroup(Group *g);
  void addMark(unsigned short mark);
  double getAverageMark();
  bool isHeadOfGroup();
  int getId() const;
  const std::string &getFullname() const;
  Group *getGroup() const;
  const std::vector<int16_t> &getMarks() const;

};

#endif  // INCLUDE_STUDENT_H_
