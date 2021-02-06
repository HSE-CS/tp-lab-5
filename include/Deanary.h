// Copyright 2021 mkhorosh
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include<vector>
#include<string>
#include"Student.h"
#include"Group.h"

class Group;
class Deanary {
  friend class Student;
  friend class Group;
 private:
  std::vector<Group *> groups = {};

 public:
  void createGroups(std::vector<std::string> titles,
                    std::vector<std::string> specs);
  void hireStudents(std::vector<std::string> fios,
                    std::vector<std::string> ids);
  void addMarksToAll();
  void getStatistics();
  void moveStudent(std::string id, std::string group);
  void saveStaff(std::string outfile);
  void initHeads();
  void fireStudents();
  void printData();
};

#endif  // INCLUDE_DEANARY_H_
