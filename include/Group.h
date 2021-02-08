// Copyright 2021 kostinandrey
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include "Student.h"
#include <string>
#include <vector>

class Student;

class Group {
 public:
    friend class Deanary;

    explicit Group(std::string title, std::string spec);
    std::string get_title();
    std::string get_spec();
    void add_student(Student* _student);
    void remove_student(Student* student);
    void choose_head();
    std::string search_student(int search_id);
    bool search_student(const std::string& search_fio);
    double average_mark_group();
 private:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student* head{};
};






#endif  // INCLUDE_GROUP_H_
