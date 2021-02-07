// Copyright 2021 Kartseva Masha
#pragma once
#define GROUP_H
#ifdef GROUP_H
#include <string>
#include <vector>
#include<time.h>
#include <iostream>
#include <cstdlib>

class Student;
class Group {
 public:
    Group(std::string title, std::string spec);
    void addStudent(Student* student);
    void expelStudent(Student* student);
    void chooseHead();
    std::string getTitle() const;
    std::string getSpec() const;
    std::string getHeadName() const;
    std::vector<Student*> getStudents() const;
    unsigned int AverageMarkofGroup() const;
    Student* findbyName(std::string name) const;
    Student* findbyId(int id) const;
 private:
    std::string title;
    std::string spec;
    std::vector <Student*> students;
    Student* head;
};

#endif  // GROUP_H
