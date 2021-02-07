// Copyright 2021 Bogomazov
#ifndef _INCLUDE_GROUP_H
#define _INCLUDE_GROUP_H
#include <vector>
#include <string>
#include "../include/Student.h"

class Group{
 public:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student *head;
    Group(std::string _title,
        std::string _spec,
        std::vector<Student*> _students = std::vector<Student*>(),
        Student *_head = NULL):
        title(_title),
        spec(_spec),
        students(_students),
        head(_head) {}
    Group createGroup(std::string title);
    void addStudentToGroup(Student* student);
    void chooseHeadman(Student* student);
    Student* findStudent(std::string fio);
    float calculateMeanMark();
    bool removeStudentFromGroup(Student* student);
};


#endif  // _INCLUDE_GROUP_H
