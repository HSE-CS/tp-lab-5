// Copyright 2021 Galex

#ifndef TP_LAB_5_INCLUDE_DEANARY_H_
#define TP_LAB_5_INCLUDE_DEANARY_H_
#include <string>
#include <vector>
#include "Group.h"
class Deanary{
 private:
  std::vector<Group> groups;
  std::string faculty;

 public:
  void createGroups();
  void hireStudents();
  void fireStudent(Student* student);
  void moveStudent(Student* student, Group* a, Group* b);
  void initHeads;

};

#endif //TP_LAB_5_INCLUDE_DEANARY_H_
