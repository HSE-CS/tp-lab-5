// Copyright 2021 Bekina Svetlana
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Student.h"

class Student;

class Group {
    friend class Deanary;
 public:
    Group();
    explicit Group(std::string, std::string);
    ~Group();
    void addStudent(Student*);
    void chooseHead();
    double getAveragemark() const;
    Student* getStudent(std::string) const;
    bool containsStudent(std::string) const;
    void removeStudent(std::string);
    bool isEmpty() const;
    std::string getTitle() const;
    std::vector<Student*> getStudents() const;
    Student* getHead() const;

 private:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student* head;
};
#endif  // INCLUDE_GROUP_H_

