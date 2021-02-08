// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <vector>
#include <string>
#include "Deanary.h"
#include "Student.h"

class Student;

class Group {
    friend class Deanary;
    friend class Student;

 private:
    std::string title;
    std::string spec;
    std::vector <Student*> students;
    Student* head;

 public:
    Group() {}
    Group(std::string name, std::string speciality);
    void addStudent(Student* newStudent);
    void chooseHead();
    Student* find(std::string key);
    float averageGroupMark();
    void goodbyeStudent(std::string id);
};


#endif   // INCLUDE_GROUP_H_
