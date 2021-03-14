// Copyright 2021 Grachev Alexander

#include "../include/Group.h"

Group::Group(std::string title, std::string spec) {
    this->title = title;
    this->spec = spec;
}

std::string Group::getTitle() {
    return title;
}

std::string Group::getSpec() {
    return spec;
}

std::string Group::getLeader() {
    return head->getName();
}

void Group::addStudent(Student newStudent) {
    students.push_back(newStudent);
    if (&newStudent.getGroup() != this) {
        newStudent.addGroup(*this);
    }
}

void Group::removeStudent(unsigned int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            students[i].group = nullptr;
        }
    }
}

void Group::removeStudent(std::string name) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].name == name) {
            students.erase(students.begin() + i);
            students[i].group = nullptr;
        }
    }
}

void Group::chooseLeader(Student newLeader) {
    this->head = &newLeader;
}

Student Group::searchStudent(unsigned int id) {
    for (auto &student : students) {
        if (student.id == id) {
            return student;
        }
    }
    throw;
}

Student Group::searchStudent(std::string name) {
    for (auto &student : students) {
        if (student.name == name) {
            return student;
        }
    }
    throw;
}

double Group::getMidMark() {
    double result = 0;
    for (auto student : students) {
        result += student.getMidMark();
    }
    return result / students.size();
    return 0;
}
