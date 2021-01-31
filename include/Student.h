//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>

class Group;

class Student {
 private:
  int ID_;
  std::string fio_;
  Group* group_;
  std::vector<int> marks_;
  void addMark(int mark);
  void addToGroup(Group* group);
  friend class Group;
  friend class Deanary;

 public:
  Student(int new_ID, std::string new_fio):
  ID_(new_ID), fio_(new_fio), group_(nullptr) {}
  Student(const Student& another_student):
  ID_(another_student.ID_), fio_(another_student.fio_),
  group_(another_student.group_), marks_(another_student.marks_) {}
  int getID() const { return ID_; }
  std::string getFio() const { return fio_; }
//  Group* getGroup() const { return group_; }
  std::vector<int> getMarks () { return marks_; }
  bool isHeadOfGroup() const;
  float getAverageMark() const;
};

#endif  // INCLUDE_STUDENT_H_
