// Copyright 2021 Kuznetsov Mikhail
#ifndef DEANARY_GROUP_H_
#define DEANARY_GROUP_H_

#include <vector>
#include <string>
#include "Student.h"
#include "Group.h"

class Deanary {
 private:
    std::vector <Group*> groups;

 public:
    void createGroups(std::string filename);
    void hireStudents(std::string filename);
    void addMarksToAll();
    void getStatistics();
    void moveStudents();
    void saveStaff();
    void initHeads();
    void fireStudents();
};
#endif  // INCLUDE_DEANARY_H_

