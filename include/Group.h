// Copyright 2021 Bogomazov
#ifndef _INCLUDE_GROUP_H
#define _INCLUDE_GROUP_H
#include <vector>
#include <string>
#include "../include/Student.h"

class Group{
 private:
    std::string _title;
    std::string _spec;
    Student *_head;

 public:
    std::vector<Student*> students;
    Group(std::string title,
        std::string spec,
        std::vector<Student*> _students = std::vector<Student*>(),
        Student *head = NULL):
        _title(title),
        _spec(spec),
        _head(head),
        students(_students) {}
    std::string getTitle();
    std::string getSpec();
    Student* getHeadman();
    void setTitle(std::string title);
    void setSpec(std::string spec);
    Group createGroup(std::string title);
    void addStudentToGroup(Student* student);
    void chooseHeadman(Student* student);
    Student* findStudent(std::string fio);
    float calculateMeanMark();
    bool removeStudentFromGroup(Student* student);
};


#endif  // _INCLUDE_GROUP_H
