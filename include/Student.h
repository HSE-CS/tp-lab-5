// Copyright 2020 Stanislav Stoianov

#ifndef TP_LAB_5_INCLUDE_STUDENT_H_
#define TP_LAB_5_INCLUDE_STUDENT_H_

#include <string>
#include <vector>
#include "Group.h"

class Group;

class Student {
 private:
  int id;
  std::string fullname;
  Group *group;
  std::vector<unsigned short> marks;
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

  const std::vector<unsigned short> &getMarks() const;

};

#endif //TP_LAB_5_INCLUDE_STUDENT_H_
