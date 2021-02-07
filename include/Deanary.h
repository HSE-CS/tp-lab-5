//Copyright 2021 Sozinov Kirill
#ifndef INCLUDE_DEANERY_H_
#define INCLUDE_DEANERY_H_

#include "Group.h"
#include <cstdlib>
#include <stdio.h>
#include <utility>
#include <Windows.h>

class Deanery {
 private:
     std::vector <Group *> groups{};
     std::vector <std::pair<size_t, std::string>> unalloc;
 public:
     Deanery();
     void createStudents();
     std::stringbuf getAllStudents();
     void printAllStudents();
     void createGroups();
     std::string getNameOfGroup(Group *group);
     std::stringbuf getNameOfGroups();
     void hireStudents();
     std::stringbuf getGroupsWithStudents();
     void printGroups();
     void addMarksToAll();
     std::stringbuf makeStatistics();
     void printStatistics();
     void moveStudents(std::vector<Student *> moving, Group *group);
     Group *getGroup(size_t ind);
     void fireStudents(double min_avg);
     void saveStaff();
     void initHeads();
     std::stringbuf getHeads();
     void printHeads();
     std::vector<Group *> getGroups() const;
};

#endif  // INCLUDE_DEANERY_H_
