// Copyright 2020 S. BOR
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include "Group.h"

class Deanary
{
 private:
  std::vector<Group *> groups;
  friend class Group;
  friend class Student;

 public:
  void createGroups();
  void createStudents();
  void AddRandomMarks();
  void GetStatistics();
  void moveStudent(Student *student, Group *dest);
  void initHeads();
  void saveStaff();
  void fireStudents();
};

#endif  // INCLUDE_DEANARY_H_
