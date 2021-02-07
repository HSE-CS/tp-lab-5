// Copyright 2021 Nikolaev Ivan

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

class Deanary;
class Student;

class Group {
    friend class Student;
    friend class Deanary;
 public:
     Group(std::string title, std::string spec);
     double getAveragemark();
     Student* getStudent(int id);
     Student* getStudent(std::string fio);
     bool containsStudent(int id);
     bool containsStudent(std::string fio);
     bool isEmpty();
 private:
     std::string title;
     std::string spec;
     std::vector<Student*> students;
     Student* head;

     void addStudent(Student *student);
     void chooseHead(Student *student);
     void removeStudent(Student *student);

};

#endif  // INCLUDE_GROUP_H_