// Copyright 2020 Uskova
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <string>
#include <vector>
#include "Student.h"

class Student;

class Group {
 private:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student* head;
    void addStudent(Student*);
    Student* chooseRandHead();
    void chooseHead(Student*);
    void removeStudent(Student*);
 public:
    Group();
    explicit Group(std::string);
    explicit Group(std::string, std::string);
    Student* getStudent(int);
    Student* getStudent(std::string);
    float getAverageMark();
    bool containsStudent(Student*);
    bool isEmpty();
    Student* getHead();
    std::string getTitle();
    std::string getSpec();
    friend class Deanary;
};

#endif  // INCLUDE_GROUP_H_
