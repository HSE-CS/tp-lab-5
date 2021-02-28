// Copyright 2021 ArinaMonicheva

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>

class Group;

class Student {
 private:
  unsigned id;
  std::string fio;
  Group* group;
  std::vector<int> marks;
  bool isHead;

 public:
  Student(unsigned newId, std::string fullName);
  void addToGroup(Group* newGroup);
  void addMark(int newMark);
  double getAverageMark();
  bool isHeadOfGroup();

  friend class Group;
  friend class Deanery;
};

#endif  // INCLUDE_STUDENT_H_
