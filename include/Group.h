// Copyright 2021 Igumnova Natasha
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include "Student.h"
#include <iostream>
#include <vector>
#include <string>
class Student;

class Group {
    friend class Student;
    friend class Deanary;
 private:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student* head;
    void addStudent(Student* student_);
    void chooseHead();
    void removeStudent(Student* student_);

 public:
	explicit Group() {
		this->title = "";
		this->spec = "";
		this->head = nullptr;
    }
    explicit Group(std::string title_, std::string spec_) {
        this->title = title_;
        this->spec = spec_;
        this->head = nullptr;
    }
    std::string getTitle();
    double getAvaragemark();
    Student* getStudent(int id);
    bool containsStudents(Student* st);
    bool isEmpty();
};
#endif  // INCLUDE_GROUP_H_