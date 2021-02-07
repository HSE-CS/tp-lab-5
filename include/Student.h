// Copyright 2020 me
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>
#include "Group.h"
#include "Deanary.h"

class Group;
class Deanary;

class Student {
  friend class Group;
  friend class Deanary;
 private:
  Group* group;
  unsigned id;
  unsigned iq;
  static unsigned count;
  std::string fio;
  std::vector<unsigned int> marks;
  bool isHead;

 protected:
  void addToGroup(Group* gr);

 public:
  explicit Student(std::string new_fio, unsigned new_iq = 90) {
      fio = new_fio;
      id = count;
      iq = new_iq;
      isHead = false;
      ++count;
  }
  ~Student() {
      marks.clear();
  }
  std::string getFio();
  unsigned getId();
  float getAveragemark();
  bool isHeadOfGroup();
  void addMark(int mark);
};

#endif  // INCLUDE_STUDENT_H_
