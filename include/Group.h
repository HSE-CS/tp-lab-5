// Copyright 2021 Stolbov Yaroslav

#ifndef INCLUDE_GROUP_H
#define INCLUDE_GROUP_H

//#include "Student.h"
#include <vector>
class Student;

class Group {
private:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student* head;
public:
    friend class Deanary;
    explicit Group(std::string title, std::string spec);
    void addStudent(Student);
    void chooseHead(Student);
    Student search_student(unsigned int);
    Student search_student(std::string);
    double groupMiddleMark();
    void removeStudent(unsigned int);
    void removeStudent(std::string);
};


#endif // INCLUDE_GROUP_H
