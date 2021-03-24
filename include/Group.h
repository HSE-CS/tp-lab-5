// Copyright 2021 Tyulin Igor

#ifndef TP_LAB_5_GROUP_H
#define TP_LAB_5_GROUP_H

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
    Group(std::string title, std::string spec);
    std::string getspec();
    std::string getitle();
};
#endif //TP_LAB_5_GROUP_H
