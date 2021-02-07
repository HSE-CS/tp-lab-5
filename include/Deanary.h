#ifndef Daenary_h
#define Daenary_h

#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
#include <fstream>
#include <stdio.h>
#include "Group.h"

class Group;
class Student;

class Deanary {
    friend class Group;
private:
    std::vector<Group*> groups;
public:
    Deanary() {}
    void createGroups(std::ifstream file);
    void readStudents(std::ifstream file);
    void addGroup(Group* name);
    void addStudents(Student* newOne, std::string groupName);
    void addMarksToAll();
    void getStatistic();
    void moveStudents(Student* student, std::string groupName);
    void saveStaff();
    void initHeads(std::string, std::string);
    void fireStudents(std::string, std::string);
    Student* getStudent(std::string, std::string);
    Group* getGroup(std::string);
};

#endif /* Daenary_h */
