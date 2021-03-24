// Copyright 2021 Tyulin Igor

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include "Student.h"
#include <string>
#include <vector>

class Student;
class Deanary;

class Group {
    friend class Student;
    friend class Deanary;
 private:
    std::string title;
    std::string spec;
    std::vector<Student *> students;
    Student *head;
 public:
    void addstud(Student *stud);
    void kickstud(Student *student);
    Student* findstud(int id);
    Student* findstud(std::string fio);
    double studavermarks();
    void sethead(Student *head);
    std::string gethead();
    Group(std::string title, std::string spec);
    std::string getspec();
    std::string getitle();
};
#endif  // INCLUDE_GROUP_H_
