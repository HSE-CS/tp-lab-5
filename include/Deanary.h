// Copyright 2021 idpas
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include <iostream>
#include <string>
#include "Student.h"
#include "Group.h"

class Student;
class Group;

class Deanary {
 private:
  Group* groups;

 public:
  Deanary();
  explicit Deanary(/*??*/);
  void ÑreateGroups(/*??*/);
  void HireStudents();
  void AddMarksToAll();
  void GetStatistics();
  void MoveStudents();
  void SaveStaff();
  void InitHeads();
  void FireStudents();
};

#endif  // INCLUDE_DEANARY_H_