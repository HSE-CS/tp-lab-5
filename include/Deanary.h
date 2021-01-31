// Copyright 2020 Khoroshavina Ekaterina
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include "Group.h"

class Deanery {
private:
    std::vector<Group*> groups;
public:
    void createGroup(std::string groupName);
    void hireStudents(Group* group, std::string fio);
    void addMarksToAll(int mark);
    void getStatistics();
    void moveStudents(Group *fromGroup, Group *toGroup);
    void fireStudents(int lowMark);
    void saveStaff();
    void initHeads();
    void getStatistics();
    std::vector<Group*> &getGroups();
};


#endif  // INCLUDE_DEANARY_H_
