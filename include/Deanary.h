// Copyright 2020 me
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <fstream>
#include "json/include/nlohmann/json.hpp"
#include "Group.h"

class Group;

class Deanary {
 private:
  std::vector<Group*> specList;
  std::vector<Group*> *groups;

 public:
  Deanary(std::string path = "") {
    groups = new std::vector<Group *>();
    if (path != "") {
      createGroups(path);
    }
  }
  ~Deanary() {
    specList.clear();
    groups->clear();
  }
  void createGroups(std::string path = "groups.json");
  void createGroups(std::string spec, std::string title);
  void createGroups(Group* gr);
  void hireStudents(std::string path = "data.json", int num = -1);
  void addMarksToAll();
  void getStatistics(std::string path = "statistic.txt");
  void moveStudents(unsigned st_id, std::string gr_title);
  Group* getGroupByTitle(std::string title);
  void saveStaff(std::string path = "save.txt");
  void initHeads();
  void fireStudents(unsigned st_id);
};

#endif  // INCLUDE_DEANARY_H_
