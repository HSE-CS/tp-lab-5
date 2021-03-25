// Copyright 2021 Tyulin Igor

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Group.h"

class Group;
class Student;

class Deanary {
    friend class Group;

    friend class Student;

 private:
    std::vector<Group *> groups;
    std::vector<Student> Students;
 public:
    void createGroups(Group group);
    void createGroups(std::ifstream& students_file);
    void hireStudents(Student *stud, std::string ng);
    void hireStudents(std::string path);
    void addMarksToAll();
    void getStatistics();
    void initHeads();
    void moveStudents(Student* student, std::string groupName);
    void saveStaff(std::string str);
    void fireStudent(const std::vector<Student *> &students);
};

#endif  // INCLUDE_DEANARY_H_
