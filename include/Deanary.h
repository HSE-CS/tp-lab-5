// Copyright 2021 Artem Danyaev
#pragma once
#include "Group.h"

class Group;

class Deanary {
 private:
  unsigned int idCounter = 1;
  std::vector<Group *> groups;

 public:
  void createGroupsFromFile(std::string path);
  void hireStudentsFromFile(std::string path);
  void createGroup(std::string title, std::string spec);
  void hireStudent(std::string fio, std::string groupTitle);
  Group *getGroup(std::string title);
  void addMarksToAll();
  void getStatistics(std::string path);
  void moveStudent(Student *student, std::string name);
  void saveStuff(std::string path);
  void initHeads();
  void fireStudents(std::vector<Student *> &students);
};
