// Copyright 2021 Grachev Alexander

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <string>
#include <vector>
#include "Student.h"


class Student;
class Deanary;

class Group {
 private:
    std::string title;
    std::string spec;
    Student *head{};

 public:
    friend class Deanary;

    std::vector<Student> students;

    Group(std::string title, std::string spec);

    std::string getTitle();
    std::string getSpec();
    std::string getLeader();
    void addStudent(Student newStudent);
    void removeStudent(unsigned int id);
    void removeStudent(std::string name);
    void chooseLeader(Student newLeader);
    Student searchStudent(unsigned int id);
    Student searchStudent(std::string name);
    double getMidMark();
};


#endif  // INCLUDE_GROUP_H_
