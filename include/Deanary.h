// Copyright 2021 soda
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <vector>
#include <string>
#include <Student.h>


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
    int get_gr_num();
    int get_st_num();
    int get_mv_num();
    int get_fi_num();
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

#endif  // INCLUDE_DEANARY_H_
