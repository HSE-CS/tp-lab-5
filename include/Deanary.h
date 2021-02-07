// Copyright 2021 Artyom Lavrov


#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include "Group.h"


class Student;
class Deanary {
  #include <vector>
 private:
  std::vector<Group*> groups;

 public:
  void createGroups();
  static std::vector<Student*> createStudents();
  static void moveStudents(std::vector<Student*> students,
       Group* from,
       Group* to);
  void addRandomMarksToAll();
  void initHeads();
  void getStatistics();
  void saveStaff();
  const std::vector<Group*>& getGroups() const;
};

#endif  // INCLUDE_DEANARY_H_
