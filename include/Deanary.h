// Copyright 2021 VadMack

#ifndef INCLUDE_DEANARY_H
#define INCLUDE_DEANARY_H

#include "Group.h"

class Student;
class Deanary{
 private:
  //Group **groups;
  std::vector<Group *> groups;

 public:
  void createGroups();
  static std::vector<Student *> createStudents();
  static void moveStudents(std::vector<Student *> students, Group *from, Group *to);
  void addRandomMarksToAll();
  void initHeads();
  void getStatistics();
  void saveStaff();
  //Group **getGroups() const;
  const std::vector<Group *> &getGroups() const;

};


#endif // INCLUDE_DEANARY_H