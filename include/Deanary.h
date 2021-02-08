// Copyright 2021 kostinandrey
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include <iostream>
#include <string>
#include <vector>
#include "Group.h"
#include "Student.h"

class Group;
class Student;

class Deanary {
 public:
    void add_student(std::ifstream& students_stream);
    void add_group(std::ifstream& groupsStream);
    void add_random_marks();
    double get_statistic_students(const std::string& name);
    double get_statistic_groups(const std::string& spec);
    void move_student(const std::string& _name, const std::string& _spec);
    void fire_students(const std::vector<Student *> &students);
    void choice_head();
    void print();
    void save_staff(std::string path);
    void students_from_file(std::string path);
    void groups_from_file(std::string path);
 private:
    std::vector<Group*> groups;
    std::vector<Student> Students;
    Group *find_group(std::string title);
    Student* find_student(unsigned int id);
};

#endif  // INCLUDE_DEANARY_H_
