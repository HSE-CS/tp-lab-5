// Copyright 2020 Dmitry Vargin
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <map>
#include <string>
#include <vector>
#include <random>

#include "Group.h"

class Deanery {
 private:
    std::vector<Group*> groups;
    static std::string getProjectPath();
 public:
    Deanery();
    std::string path_to_data;
    void hireStudents(std::string filename);
    void createGroups(std::string filename);
    void addMarksToAll(int marks_per_student);
    void moveStudents(Student *student, Group *group);
    Student *fireStudents(Student *student);
    void initHeads();
    std::map<Group *, double> getStatistics();
    void saveStaff();

    std::vector<Group*> getGroups();
    void addGroup(Group *group);
};


#endif  // INCLUDE_DEANARY_H_
