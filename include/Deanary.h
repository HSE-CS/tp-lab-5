// Copyright 2020 GHA Test Team
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include <iostream>
#include <vector>
#include <string>
#include "DataReader.h"
#include "Group.h"


class Student;
class Group;

class Deanary {
 private:
  Group* groups;
  unsigned number_of_groups;
  std::string students_file_name, groups_file_name;
  DataReader* reader;

 public:
  Deanary();
  explicit Deanary(unsigned number_of_groups, std::string students_file_name,
    std::string groups_file_name, bool random_division = false);
  int getNumberOfGroups() const;
  std::vector<Student*> hireStudents(std::string, std::string format = "txt");
  bool fireStudents();
  void createGroups(std::vector<Student*>, std::string,
    bool random_division = false, std::string format = "txt");
  void addMarksToAll(unsigned, bool random = false);
  void printDeanary(bool marks_on = false);
  std::vector<Student*> findBestStudents(Group*);
  std::vector<Student*> findWorstStudents(Group*);
  unsigned* findNumberOfCatigoriesOfStudents(Group*);
  Student* findStudentByFio(std::string);
  Group* findGroupByTittle(std::string);
  void printStatistics();
  void moveStudents(std::string, std::string);
  void saveStaff(std::string new_students_file_name = "students.txt",
    std::string new_goups_file_name = "groups.txt");
  void initHeads();
};
#endif  // INCLUDE_DEANARY_H_
