//
//  Deanary.hpp
//  programming-technologies
//
//  Created by Даниил Иванов on 07.02.2021.
//  Copyright © 2021 Daniil Ivanov. All rights reserved.
//

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <stdio.h>
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
