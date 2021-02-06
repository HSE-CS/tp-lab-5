// Copyright 2021 GN
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <iostream>
#include <string>
#include <vector>
#include <Student.h>
class Student;
class Group {
    friend class Deanary;
 private:
    std::string title;
    std::string spec;
    Student* head;

 public:
    std::vector<Student*> students;
    Group(std::string title_, std::string spec_) {
        title = title_;
        spec = spec_;
    }
    std::string getName();
    std::string getSpec();
    void addStudent(Student* student);
    Student& getStudent(const std::string& fio);
    Student& getStudent(int id);
    void initHead();
    Student& getHead();
    double av_mark();
    void delStudent(Student* st_);
};
#endif  //  INCLUDE_GROUP_H_
