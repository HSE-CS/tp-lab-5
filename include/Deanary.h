// Copyright 2021 soda
#ifndef LAB_5_DEANERY_H
#define LAB_5_DEANERY_H

#include <vector>
#include <string>
#include "Student.h"


class Student;

class Group;

class Deanary {
private:
    std::vector<Group*>* groups;
    int group_num;
    int student_num;
    int moved_num;
    int fired_num;
    Group& GetGroupByStudent(int);
    Group& GetGroupByStudent(const std::string&);
    Group& getGroup(const std::string&);
    std::stringbuf createStat();
public:
    Deanary();
    void get_create_inf();
    void createGroups();
    void hireStudents();
    void addMarksToAll(int);
    void moveStudents(int, std::string&);
    void moveStudents(std::string&, std::string&);
    void move_report(Student&, Group&, Group&);
    void saveStuff();
    void printStat();
    void initHeads();
    void fireStudents(int);
    void fireStudents(std::string&);
    void fire_report(Student&);
    void fireWeakStudents();
    ~Deanary();
};

#endif  // LAB_5_DEANERY_H