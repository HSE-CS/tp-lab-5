// Copyright 2020 Dumarevskaya
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <fstream>
#include <vector>
#include <string>
#include "Group.h"

class Deanary {
  friend class Student;
  friend class Group;
 private:
  std::vector<Group*> groups;

 public:
  Deanary() {}
  explicit Deanary(std::ifstream file) {
    std::string gro, title, spec;
    while (getline(file, gro)) {
      title = gro.substr(0, gro.find(", ") - 1);
      spec = gro.substr(gro.find(", ") + 1);
      groups.push_back(new Group (title, spec));
    }
  }
  ~Deanary() {}
  void createGroup();
  void addGroup(Group*);
  void hireStudents(Student*, std::string);
  void addMarksToAll(uint64_t, std::string);
  void getStatistic();
  void moveStudents(std::string, std::string, std::string);
  void saveStaff();
  void initHeads(std::string, std::string);
  void fireStudents(std::string, std::string);
  Student* getStudent(std::string, std::string);
  Group* getGroup(std::string);
};

#endif  // INCLUDE_DEANARY_H_
