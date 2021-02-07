// Copyright 06.02.21 DenisKabanov

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include "Student.h"

class Student;

class Group {
 private:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student* head = nullptr;

 public:
    explicit Group(std::string newtitle);
    Group(std::string newtitle, std::string newspec);
    void addStudent(Student* newstudent);
    void chooseHead();
    void addspec(std::string newspec);
    Student* getStudent(unsigned int findid);
    Student* getStudent(std::string findfio);
    float getAveragemark();
    Student* getHead();
    void removeStudent(Student* delstudent);
    bool isEmpty();
    std::vector<Student*> containsStudents();
    std::string getTitle();
    std::string getSpec();
    int getStudents();
};

#endif  // INCLUDE_GROUP_H_
