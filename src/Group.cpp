// Copyright 2021 soda

#include <iostream>
#include <Deanary.h>
#include <Group.h>


void Group::addStudent(Student& student) {
    students->push_back(&student);
}

std::string Group::getTitle() {
    return title;
}

Student& Group::getHead() {
    return *this->head;
}

bool Group::isEmpty() {
    return this->students->empty();
}

Group::~Group() {
    for (auto student : *students) {
        delete student;
    }
    delete students;
}