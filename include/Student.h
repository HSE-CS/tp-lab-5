// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 06.02.2021.
//
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>

class Group;

class Student {
 private:
    unsigned int id;
    std::string fio;
    Group* group;
    bool isHead;
    std::vector <int> marks;
    Student(unsigned int id, std::string,std::vector <int>, Group* = nullptr);
    Student(unsigned int id, std::string, Group* = nullptr);
    void addToGroup(Group* group);
    void addMark(int);
    void addHead();
 public:
    double getAvrMark() const;
    bool isHeadGroup() const;
    friend class Group;
    friend class Deanary;
};

#endif  // INCLUDE_STUDENT_H_