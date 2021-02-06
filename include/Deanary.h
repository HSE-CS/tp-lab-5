// Copyright 2021 Khoroshavina Ekaterina
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include "Group.h"
#include <string>
#include <vector>

class Deanary {
 private:
    std::vector<Group*> groups;
    int num_gr;
 public:
    Deanary();
    ~Deanary();
    void createGroup(std::string name, std::string sp);
    void addGroup(Group* group);
    void hireStudents(Group* group, std::string fio);
    void addMarksToAll(int mark);
    void getStatistics();
    void moveStudent(Group* fromGroup, Group* toGroup, Student* student);
    void fireStudents(int lowMark);
    void saveStaff();
    void initHeads();
    void initHeadsIfNone();
    std::vector<Group*> &getGroups();
};

#endif  // INCLUDE_DEANARY_H_
