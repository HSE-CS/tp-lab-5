// Copyright 2021 Lab_5 TiNa
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <string>
#include <vector>
#include "Student.h"

class Student;
class  Group {
    friend class Deanary;
 private:
     std::string title;
     std::string spec;
     Student* head;

 public:
     std::vector<Student*> students;
     explicit Group(std::string title, std::string spec);
     void addStudent(Student* student);
     void delStudent(Student* student);
     void chooseHead();
     Student* getStudent_id(int id);
     Student* getStudent_fio(std::string& fio);
     double getAveragemark_Gr();
     void removeStudent(Student* student);
     bool isEmpty();
     std::string getTitle();
     std::string getSpec();
};

#endif  // INCLUDE_GROUP_H_
