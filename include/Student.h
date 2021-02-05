// Copyright 2021 Andrey Bakurskii

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>
#include "Group.h"


class Group;
class Deanary;

class Student {
  friend class Group;
  friend class Deanary;

 private:
  int id;
  std::string fio;
  Group* group;
  std::vector<int> marks;
  void addToGroup(Group*);
  void addmark(int mark);

 public:
  Student();
  explicit Student(int, std::string);
  explicit Student(Student*);
  float getAveragemark();
  bool isHeadOfGroup();
  std::string getFIO();
  int getId();
};

#endif  // INCLUDE_STUDENT_H_
