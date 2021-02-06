// Copyright 2021 mkhorosh
#ifndef INCLUDE_DEANERY_H_
#define INCLUDE_DEANERY_H_
#include<vector>
#include<string>
#include"Student.h"
#include"Group.h"

class Deanary{
  friend class Student;
  friend class Group;
 private:
  std::vector<Group*>groups={};

 public:
  void createGroups(std::vector<std::string> titles, std::vector<std::string> specs);
  void hireStudents(std::vector<std::string> fios, std::vector<std::string> ids);
  void addMarksToAll();
  void getStatistics();
  void moveStudent(std::string id, std::string group);
  void saveStaff(std::string outfile);
  void initHeads();
  void fireStudents();
  void printData();
};

#endif  // INCLUDE_DEANERY_H_
