// Copyright 2021 Shirokov Alexander

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>

#include "Group.h"

class Group;
class Deanary {
 private:
  std::vector <Group*> groups;
 public:
  Deanary() = default;
  void createGroups(const std::string& path);
  void hireStudents(const std::string& path);
  void addMarksToAll();
  void getStatistics();
  void moveStudents(Group* from, Group* to, std::vector<Student*> students);
  void saveStaff(const std::string& studentsPath, const std::string& groupsPath);
  void initHeads();
  void fireStudents(std::vector<Student*> students);
  std::vector<Group*> getGroups();
};
