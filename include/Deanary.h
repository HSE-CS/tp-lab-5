// Copyright 2021 Galex

#ifndef TP_LAB_5_INCLUDE_DEANARY_H_
#define TP_LAB_5_INCLUDE_DEANARY_H_
#include <string>
#include <vector>
#include "../include/Group.h"

class Deanary {
 private:
  std::vector<Group *> groups;
  std::string spec;
  unsigned int nextId;

 public:
  explicit Deanary(std::string spec);
  void createGroups();
  void createGroup(std::string name);
  void hireStudents();
  void hireStudent(std::string fio, int groupNum);
  void fireStudent(unsigned int id);
  void moveStudent(Student *student, Group *a, Group *b);
  void initHeads();
  Group* getGroup(int number);
  void addMarks2All(int numOfMarks);
  double getAverage();
  void saveState();
};

#endif  // TP_LAB_5_INCLUDE_DEANARY_H_
