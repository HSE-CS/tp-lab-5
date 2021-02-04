// Copyright 2021 Bodrov Egor
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <vector>
#include <string>

#include "Student.h"

class Student;

class Group {
    friend class Student;
    friend class Deanary;
 private:
     std::string title;
     std::string spec;
     std::vector <Student*> students;
     Student* head = nullptr;

 public:
     explicit Group(const std::string& title_, const std::string& spec_);
     double getAveragemark();
     Student* getStudent(int id);
     Student* getStudent(const std::string& name);
     bool isEmpty();
     void addStudent(Student* student);
     void chooseHead(Student* student);
     void removeStudent(Student* student);
};

#endif  // INCLUDE_GROUP_H_