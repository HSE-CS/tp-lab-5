// Copyright 2021 Bogomazov
#ifndef _INCLUDE_GROUP_H
#define _INCLUDE_GROUP_H
#include <vector>
#include <string>
#include "../include/Student.h"
class Group {
 private:
    std::string _title;
    std::string _spec;
    std::vector<Student> _students;
    Student _head;
 public:
    Group(std::string title,
        std::string spec,
        std::vector<Student> students,
        Student head):
        _title(title),
        _spec(spec),
        _students(students),
        _head(head) {}
    bool createGroup(std::string title);
    bool addStudentToGroup(Student student);
    bool chooseHeadman(Student student);
    Student findStudent(std::string fio);
    float calculateMeanMark();
    bool removeStudentFromGroup(Student student);
};

#endif  // _INCLUDE_GROUP_H
