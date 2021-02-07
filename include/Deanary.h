// Copyright 2020 VladimirUspensky

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <vector>
#include "Group.h"

class Deanery {
 private:
    std::vector<Group*> groups;

 public:
    void createGroups();
    void createStudents();
    void addRandomMarks();
    void getStat();
    static void moveStudent(Student* student, Group* destination);
    void fireStudents();
    void saveNewData();
    void initHeadChoice();
    void printData();
};

#endif  // INCLUDE_DEANARY_H_
