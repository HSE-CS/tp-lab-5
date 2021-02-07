// Copyright 2021
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <string>
#include <vector>
#include "Student.h"
class Student;

class Group
{
private:
    std::string title;
    std::string spec;
    std::vector<Student> students;
    Student* head;

public:
    Group(std::string title, std::string spec);
    void addStudent(Student& student);
    void chooseHead();
    Student& getStudent(int id);
    Student& getStudent(std::string fio);
    double getAverageMark();
    void removeStudent(Student& student);
    std::string getTitle();
    std::string getSpec();
    Student* getHead();
    std::vector<Student> getStudents();
};
#endif // INCLUDE_GROUP_H_
