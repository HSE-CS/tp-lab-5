// Copyright 2020 Dmitry Vargin
#ifndef TP_LAB_5_DEANARY_H
#define TP_LAB_5_DEANARY_H

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
    void hireStudents();
    void hireStudents(std::string filename);
    void createGroups();
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

#endif //TP_LAB_5_DEANARY_H
