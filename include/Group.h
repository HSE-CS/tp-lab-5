// Copyright Roman Balayan @ 2021

#pragma once

#include <string_view>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include "../include/Student.h"
#include "../include/Deanary.h"

class Student;

class Group {
 public:
    explicit Group(const std::string title);
    Group(const std::string title, const std::string spec);
    void addStudent(std::shared_ptr<Student> student);
    bool selectHead(std::shared_ptr<Student> newHead);
    std::shared_ptr<Student> findStudent(const std::string name) const;
    std::shared_ptr<Student> findStudent(int16_t id) const;
    double getAverageScore() const;
    bool removeStudent(std::shared_ptr<Student> student);
    bool removeStudent(const std::string name);
    bool removeStudent(int16_t id);
    void printStudents() const;
 private:
    std::string title;
    std::string spec;
    std::vector<std::shared_ptr<Student> > students;
    std::shared_ptr<Student> head;

    friend class Deanary;
};
