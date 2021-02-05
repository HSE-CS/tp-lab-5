#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <iostream>
#include <string>
#include <vector>
#include "Group.h"

class Group;

class Student {
private:
  int id;
  std::vector<int> marks;
  Group* group;
  std::string fio;
  void addToGroup(Group *group);
  void addMark(int mark);
  friend class Deanary;
  friend class Group;

public:
  Student(int curr_id, std::string fullName);
  double getAveragemark();
  bool  isHeadOfGroup();
  int getId() const;
  std::string getFIO();
};

#endif // INCLUDE_STUDENT_H_

