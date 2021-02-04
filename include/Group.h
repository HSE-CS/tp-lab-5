// Copyright 2021 Kuznetsov Mikhail
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
    std::vector <Student*> students;
    Student* head = nullptr;

 public:
    explicit Group(std::string _title);
    Group(std::string _title, std::string _spec);
    void addStudent(Student* _student);
    void chooseHead();
    float getAveragemark();
    Student* getStudent(unsigned int _id);
    Student* getStudent(std::string _fio);
    std::vector <Student*> containsStudents();
    std::string getTitle();
    std::string getSpec();
    Student* getHead();
    void removeStudent(Student *_student);
    bool isEmpty();
};

#endif  // INCLUDE_GROUP_H_
