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
    Student* _head;
    std::vector<Student*> _students;

 public:
    
    Group(std::string title,
        std::string spec,
        std::vector<Student*> students = std::vector<Student*>(),
        Student *head = NULL):
        _title(title),
        _spec(spec),
        _head(head),
        _students(students) {}
    std::string getTitle();
    std::string getSpec();
    Student* getHeadman();
    std::vector<Student*> getStudents();
    void setTitle(std::string title);
    void setSpec(std::string spec);
    Group createGroup(std::string title);
    void addStudentToGroup(Student* student);
    void chooseHeadman(Student* student);
    Student* findStudent(std::string fio = "", int id = -1);
    float calculateMeanMark();
    bool removeStudentFromGroup(Student* student);
    bool isEmpty();
};


#endif  // _INCLUDE_GROUP_H
