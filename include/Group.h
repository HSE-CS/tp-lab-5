//
//  Group.hpp
//  programming-technologies
//
//  Created by Даниил Иванов on 07.02.2021.
//  Copyright © 2021 Daniil Ivanov. All rights reserved.
//

#ifndef Group_hpp
#define Group_hpp

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

#endif
