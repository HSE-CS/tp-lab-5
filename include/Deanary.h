// Copyright 2021 Andrey Rogov

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include "Group.h"
#include <vector>

class Deanary {
private:
    std::vector<Group*> groups;

public:
    std::vector<Group*> getGroups();

    void createGroups();

    std::vector<Student*> hireStudents();

    void addMarksToAll();

    void getStatistics();

    void moveStudents(Group* f, Group* t, std::vector<Student*> stds);

    void saveStaff();

    void initHeads();

    void fireStudents(std::vector<Student*> stds);

    void sortStudents(std::vector<Student*> stds);
};

#endif  // INCLUDE_DEANARY_H_