// Copyright 2021 Stolbov Yaroslav

#ifndef INCLUDE_GROUP_H
#define INCLUDE_GROUP_H

//#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Student;

class Group {
 private:
    std::string title;
    std::string spec;
    Student *head{};
 public:
    std::vector<Student> students;

    friend class Deanary;

    explicit Group(std::string, std::string);

    void addStudent(Student);

    void chooseHead(Student);

    Student search_student(unsigned int);

    Student search_student(std::string);

    double groupMiddleMark();

    void removeStudent(unsigned int);

    void removeStudent(std::string);

    std::string getGroupName();

    std::string getHead();
};


#endif // INCLUDE_GROUP_H
