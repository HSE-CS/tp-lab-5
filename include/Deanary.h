// Copyright 2021 KarMashanova
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Student.h"
#include "Group.h"

class Student;
class Group;
class Deanary {
 private:
  std::vector<Group *> *groups;

 public:
  void createGroups();
  std::vector <Student*> hireStudents();
  void addMarksToAll();
  void getStatics() const;
  void moveStudents(Group *f, Group *t, std::vector<Student *> stds);
  void moveStudents(const std::string &fio, const std::string &title);
  void saveStaff();
  void initHeads();
  void fireStudents(std::vector<Student *> stds);
  void sortStudents(std::vector<Student *> stds);


};


#endif  // INCLUDE_DEANARY_H_