// Copyright 2021 Khoroshavina Ekaterina
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include "Student.h"
#include <vector>
#include <string>

class Student;

class Group {
    friend class Deanary;
 private:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student* head;
 public:
    void addStudent(Student* student);
    void chooseHead();
    void removeStudent(Student* student);
    Group(std::string name, std::string sp);
    // ~Group();
    double getAverageMark();
    Student* getStudent(const std::string& ident);
    Student* getStudent(int id);
    Student* getHead();
    std::string getTitle();
    std::string getSpec();
    bool containsStudent(std::string ident);
    bool containsStudent(int id);
    bool isEmpty();
};

#endif  // INCLUDE_GROUP_H_
