// Copyright 2020 Stanislav Stoianov

#ifndef TP_LAB_5_INCLUDE_DEANERY_H_
#define TP_LAB_5_INCLUDE_DEANERY_H_

#include <vector>
#include "Group.h"

class Deanery {
 private:
  std::vector<Group *> groups;
 public:
  void createGroups();
  void hireStudents();
  void addMarksToAll();
  void getStatistics();
  static void moveStudents(Group * fromGroup, Group * toGroup);
  void fireStudents();
  void saveStaff();
  void initHeads();
  void outputStatistics();

};

#endif //TP_LAB_5_INCLUDE_DEANERY_H_
