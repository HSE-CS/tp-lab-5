// Copyright 2021 Stolbov Yaroslav

#ifndef INCLUDE_DEANERY_H
#define INCLUDE_DEANERY_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Group.h"
#include "Student.h"
class Deanary {
 private:
    std::vector<Group> groups;
    std::vector<Student> heads;
 public:
    const std::vector<Group> &getGroups() const;
    void createStudents(std::fstream&);
    void addRandomMarks();
    void swapGroup(Student, Group);
    void getStatistic();
    void studentExpulsion(std::fstream &);
    void initHeads();
    void printInformation();
};

#endif // INCLUDE_DEANERY_H
