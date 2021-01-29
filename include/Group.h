// Copyright 2020 Dmitry Vargin
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <string>
#include <vector>

#include "Student.h"

class Student;

class Group {
  private:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student *head;
  public:
    explicit Group(std::string title);
    void addStudent(Student *student);
    void chooseHead(Student *phead);
    Student *getStudent(int student_id);
    Student *getStudent(std::string student_fio);
    double getAveragemark();
    bool containsStudent(Student *student);
    void removeStudents(Student *student);

    bool isEmpty();

    Student *getHead();
};

#endif  //  INCLUDE_GROUP_H_
