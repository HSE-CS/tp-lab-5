// Copyright 2021 Andrey Rogov

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include "Student.h"
#include <string>
#include <vector>

class Student;

class Group {
 private:
     std::string title;
     std::string spec;
     std::vector<Student*> students;
     Student* head{ nullptr };
 
 public:
     Group(const std::string& t, const std::string& s);
 
     std::string getTitle();
 
     std::string getSpec();
 
     void addStudent(Student* s);
 
     void chooseHead(Student* h);
 
     Student* getHead();
 
     double getAverageMark();
 
     Student* getStudent(const std::string& sid);
 
     bool containsStudent(Student* s);
 
     void removeStudent(Student* s);
 
     bool isEmpty();
 
     std::vector<Student*> getStudents();
 
     ~Group();
};

#endif  // INCLUDE_GROUP_H_
