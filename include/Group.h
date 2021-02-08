// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 06.02.2021.
//

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <vector>
#include <string>
#include "Student.h"


class Student;

class Deanary;

class Group {
 private:
    int title;
    std::vector<Student *> students;
    std::string spec;
    Student *head;

    Student *getStudent(const std::string &name) const;

    Student *getStudent(unsigned int id) const;

    Student *createStudent(unsigned int id, std::string name);

    void chooseHead();

    void removeStudent(Student *);

    Group(std::string valSpec, int valTitle);

    void addStudent(Student *);


 public:
    double getAvrMark() const;

    bool containsStudent(unsigned int id) const;


    friend class Student;

    friend class Deanary;

    int getGSize();

    std::string getSpec() const;

    unsigned int getTitle() const;

    bool containsStudent(std::string name);

    bool isEmpty() const;
};

#endif  // INCLUDE_GROUP_H_
