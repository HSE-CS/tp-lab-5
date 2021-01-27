// Copyright 2020 Stanislav Stoianov

#ifndef TP_LAB_5_INCLUDE_DEANERY_H_
#define TP_LAB_5_INCLUDE_DEANERY_H_

#include <vector>
#include "Group.h"

class Deanery {
 private:
  std::vector<Group *> groups;
 public:
  void createGroups(char *dirpath);
  static void hireStudents(Group *group, char *filepath);
  void addMarksToAll();
  void getStatistics(char *dirpath);
  static void moveStudents(Group *fromGroup, Group *toGroup);
  void fireStudents(int lowMark);
  void saveStaff(char *filepath);
  void initHeads();
  void getStatistics();

  const std::vector<Group *> &getGroups() const;
};

#endif //TP_LAB_5_INCLUDE_DEANERY_H_
