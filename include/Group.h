// Copyright 2020 Khoroshavina Ekaterina
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include "Student.h"

class Student;

class Group {
private:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student* head;
    void addStudent(Student* student);
    void chooseHead();
    void removeStudent(Student* student);
public:
    double getAveragemark();
    Student* getStudent(std::string ident);
    Student* getStudent(int id);
    Student* getHead();
    std::string& getTitle();
    std::string& getSpec();
    bool containsStudent(std::string ident);
    bool containsStudent(int id);
    bool isEmpty();
};


#endif  // INCLUDE_GROUP_H_
