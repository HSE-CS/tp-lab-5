// Copyright 2021 MalininDmitry
#include "Student.h"
#include "Group.h"
#include <iostream>

Group::Group(std::string title, std::string spec) {
    this->title = title;
    this->spec = spec;
}

Group::Group(std::string title) {
    this->title = title;
}

void Group::addStudent(Student * student) {
    student->addToGroup(this);
    students.push_back(student);
}

void Group::chooseHead(Student * student) {
    head = student;
}

void Group::chooseHead() {
    srand(0);
    if (countStudent()-1 >= 1)
        head = this->students[rand() % (this->countStudent()-1)];
    else if (countStudent() > 0)
        head = this->students[0];
}

void Group::removeStudent(Student* student) {
    if (head == student)
        head = nullptr;
    student->addToGroup(nullptr);
    for (int i = 0; i < students.size(); i++) {
        if (student == students[i]) {
            students.erase(students.begin() + i);
            break;
        }
    }
}
double Group::getAverageMark() {
    double average = 0.0;
    for (int i = 0; i < students.size(); i++) {
        average += students[i]->getAveragemark();
    }
    if (students.size())
        return average/students.size();
    return 0.0;
}

Student * Group::containsStudent(int num) {
    for (int i = 0; i < students.size(); i++)
        if (students[i]->getId() == num)
            return students[i];
    return nullptr;
}
Student * Group::containsStudent(std::string fio) {
    for (int i = 0; i < students.size(); i++)
        if (students[i]->getFio() == fio)
            return students[i];
    return nullptr;
}

int Group::countStudent() {
    return static_cast<int>(this->students.size());
}

std::vector<Student*> Group::listStudent() {
    return students;
}

std::string Group::getSpec() {
    return this->spec;
}

std::string Group::getTitle() {
    return this->title;
}

bool Group::isEmpty() {
    if (!this->students.size())
        return true;
    return false;
}
