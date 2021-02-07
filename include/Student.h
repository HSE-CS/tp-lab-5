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
  unsigned short iq;
  static unsigned count;
  std::string fio;
  std::vector<unsigned int> marks;
  bool isHead;

 protected:
  void addToGroup(Group* gr);
  void addMark(int mark);

 public:
  Student(std::string new_fio, unsigned short new_iq = 90) {
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
};

#endif  // INCLUDE_STUDENT_H_
