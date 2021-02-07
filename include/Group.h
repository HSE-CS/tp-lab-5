// Copyright 2021 Stifeev Nikita

#ifndef GROUP_H
#define GROUP_H

#include "Student.h"
class Student;
class Group
{
 private:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student* head;
    double mean;
 public:
    Group(std::string title, std::string spec);
    void addStudent(Student* student);
    void chooseHead();
    int findByName(std::string name) const;
    int findByID(unsigned int id) const;
    void estimate(unsigned int id);
    int findMean() const;
    void exclude(unsigned int id);
    std::vector<Student*> getStudent();
    std::string getTitle() const;
    double calcMean();
    void excludeBadStudents();
    ~Group();
};

#endif // GROUP_H
