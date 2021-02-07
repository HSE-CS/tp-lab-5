// Copyright 2021 Tatsenko Ilya
#pragma once

#include<iostream>
#include<vector>
#include<string>
#include"Student.h"

class Student;
class Deanary;

class Group {
 private:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student* head = nullptr;
 public:

    Group(std::string name, std::string spec) {
        this->title = name;
        this->spec = spec;
    }
    void add_student(Student* student);
    void choose_header(Student* student);
    Student* find_of_student(std::string fio, int id);
    double calculate_of_avarage_mark();
    void remove_student(Student* student);
    std::string get_header() {
        return head->get_fio();
    }
    std::string get_students() {
        return students[0]->fio;
    }
    friend  Student;
    friend  Deanary;
};