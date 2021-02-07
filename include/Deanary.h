// Copyright 2021 Stifeev Nikita

#ifndef DEANARY_H
#define DEANARY_H

#include "Group.h"
#include <fstream>

class Deanary
{
 private:
    std::vector<Group*> groups;
 public:
    Deanary();
    void createGroups(std::string fileName);
    std::vector<Group*> getGroups() const;
    void createStudents(std::string fileName);
    void addMarksToAll();
    std::vector<double> getStatistics();
    void moveStudents(Student* st, Group* gr1, Group* gr2);
    void fireStudents();
    void save(std::string filename);
    ~Deanary();
};

#endif // DEANARY_H
