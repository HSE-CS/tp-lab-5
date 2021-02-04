// Copyright 2021 GN
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include <iostream>
#include <string>
#include <vector>
#include <Student.h>
#include <Group.h>
class Student;
class Group;
class Deanary {
 private:
    std::vector<Group> groups;
    std::vector<Student> allStudents;
 public:
    void addGroup(Group gr_);
    void acceptStudents();
    void createGroups();
    void studentRegistration();
    void addMarks();
    double getStatisticByStudents(std::string fio_);
    double getStatisticByGroups(std::string spc_);
    void transferStudent(std::string fio_, std::string spc_);
    void addStudent(Student* student, std::string spec_);
    void hireStudent(std::string fio_);
    void saveToFiles();
    void initOfHeadElection();
    void printAllInfo();
};
#endif  // INCLUDE_DEANARY_H_
