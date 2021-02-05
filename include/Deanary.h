// Copyright 2021 Igumnova Natasha
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include "Group.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <vector>

class Deanary {
    friend class Group;
    friend class Student;
 private:
    Group* groups;
    int count;

 public:
    explicit Deanary();
    explicit Deanary(int c, std::string file_name);
    void createGroups(std::vector<Student*>st, std::string file_name);
    std::vector<Student*> hireStudents(std::string filename);
    void addMarksToAll(std::string gr);
    void getStatistic();
    void printGroups();
    void moveStudents(int id, std::string gr);
    void saveStaff(std::string file_name);
    void initHeads();
    void fireStudents(double minMark);
    Student* findSudentId(int id_);
    Group* findGroupTitle(std::string gr);
};
#endif  // INCLUDE_DEANARY_H_