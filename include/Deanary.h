//
// Created by toliman on 03.02.2021.
//

#ifndef TP_LAB_5_DEANARY_H
#define TP_LAB_5_DEANARY_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "../include/Group.h"
#include "../include/Student.h"

//class Student;
//
//class Group;

class Deanary {
private:
    std::vector<Group *> groups;
public:
    static std::vector<Student *> createStudents(int count);

    void createGroup(const std::string &groupFile);

    std::vector<Group *> getGroups();

    static void addMark(Student &student, int count);

    void getStats();

    static void changeGroup(Student &student, Group &group);

    void removeFoolStudents();

    void save();

    void initializeHeadChoose();

};


#endif //TP_LAB_5_DEANARY_H
