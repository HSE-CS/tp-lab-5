//  Copyright © 2021 Ksuvot. All rights reserved.

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <vector>
#include "Group.h"

class Deanary {
  friend class Group;
  friend class Student;

 private:
  std::vector<Group *> groups;

 public:
  void saveData();
  void initHeadmen();
  void createGroups();
  void getStatistics();
  void createStudents();
  void setRandomMarks();
  void expulsionStudents();
  void moveStudent(Student *student, Group *group);
};

#endif  // INCLUDE_DEANARY_H_
