// Copyright 2021 Kartseva Masha
#pragma once
#define DEANARY_H
#ifdef DEANARY_H
#include "Group.h"
#include "Student.h"
#include <iostream>
#include<time.h>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

class Student;
class Group;
class Deanary {
 public:
    friend class Group;
    friend class Student;
    Deanary();
    void addGroups(std::string names_input, std::string groups_input);
    void set_random_marks(unsigned int number);
    void getStatistics() const;
    void changeGroup(std::string name, std::string oldGroup,
    std::string newGroup);
    void expelStudents();
    void rewriteData(std::string students, std::string groups) const;
    void chooseHeads();
 private:
    std::vector <Group*> groups;
    unsigned int dean_id;
};

#endif  // DEANARY_H
