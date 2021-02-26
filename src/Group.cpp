// Copyright 2021 Stolbov Yaroslav

#include <iostream>
#include <Student.h>
#include "Group.h"

Group::Group(std::string title, std::string spec) {
    this->title = title;
    this->spec = spec;
}

void Group::addStudent(Student student) {
    students.push_back(student);
    if(&student.getGroup() != this){
        students.back().addGroup(*this);
    }
}

void Group::chooseHead(Student student) {
    this->head = &student;
}

Student Group::search_student(unsigned int id) {
    for (auto & student : students){
        if (student.id == id) {
            return  student;
        }
    }
    throw;
}

Student Group::search_student(std::string fio) {
    for (auto & student : students){
        if (student.fio == fio) return student;
    }
    throw;
}

double Group::groupMiddleMark() {
    double result = 0;
    for (auto student : students) {
        result += student.getMiddleMark();
    }
    return result / students.size();
}

void Group::removeStudent(unsigned int id) {
    for(int i = 0; i < students.size(); i++) {
        if(students[i].id == id) {
            students.erase(students.begin() + i);
            students[i].group = nullptr;
        }
    }
}
void Group::removeStudent(std::string fio) {
    for(int i = 0; i < students.size(); i++) {
        if(students[i].fio == fio) {
            students.erase(students.begin() + i);
            students[i].group = nullptr;
        }
    }
}

std::string Group::getGroupName() {
    return title + " " + spec;
}

std::string Group::getHead() {
        return head->getFio();
}