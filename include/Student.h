// Copyright 2021 Kasyanov
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>

#include "Deanary.h"
#include "Group.h"
#include "ReadGroup.h"

class ReadGroup;
enum ABILITY { OK, GOOD, EXCELLENT };

class Student {
 private:
  int id;
  std::string fio;
  Group* group;
  std::vector<int> marks;
  ABILITY skill;
  bool isHead;
  void AddToGroup(Group*);
  void AddMark(int);

 public:
  Student(int, std::string, Group*);
  double GetAverageMark() const;
  bool IsHeadOfGroup() const;
  std::string GetName() const;

  friend class Group;
  friend class ReadGroup;
  friend class Deanary;
};

#endif  // INCLUDE_STUDENT_H_
