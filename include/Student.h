//  Copyright 2020 GHA created by Klykov Anton

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include "Group.h"
#include <iostream>
#include <vector>
#include <cstring>

class Group;
class Student {
 private:
  static int m_id;
  int id;
  std::string FinSenThn;  // Фамилия, имя, отчество
  Group* group;
  std::vector<unsigned int> marks;
  bool isHead{false};
  void addToGroup(Group* _gr);
  void addMark(int iteration);

 public:
  Student(const std::string& fio);
  [[nodiscard]] size_t getId() const;
  double getAverageMark();
  [[nodiscard]] bool isHeadOfGroup() const;
  Group* getGroup();
  int getAmountMarks();
  friend class Deanary;
  friend class Group;
};

#endif  // INCLUDE_STUDENT_H_
