// Copyright 2021 Egor Trukhin
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "Group.h"

class Deanary {
 private:
  uint32_t students_counter = 1;  // for unique students' id
  std::vector<Group*> groups;

 public:
  Deanary() {}  // for unit tests
  Deanary(const char* filename_groups, const char* filename_students);
  ~Deanary();

  // Setters
  void setRandomMarks(uint32_t count);
  void setHeads();

  // Changers
  void fireStudents();                 // if mean mark less than group mean mark
  void fireStudents(double min_mark);  // if mean mark less than "min_mark"
  void fireStudents(const std::vector<Student*>& fire_list);
  void moveStudents(const std::vector<Student*>& move_list, Group* new_group);

  // Getters
  const std::vector<Group*>& getGroups() const;
  Group* getGroup(const std::string& title);
  std::string getInfo() const;

  void saveData(const char* filename_groups, const char* filename_students);

  //===========================================
  // public for unit tests (should be private):

  // INPUT: vector < "GROUP_TITLE SPEC" >
  void createGroups(const std::vector<std::string>& groups_info);

  // INPUT: vector < "NAME GROUP_TITLE" >
  void hireStudents(const std::vector<std::string>& students_info);

  //===========================================
};

#endif  // INCLUDE_DEANARY_H_
