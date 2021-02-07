// Copyright 2021 Lab_5 TiNa
#include "Group.h"
#include <iostream>

Group::Group(std::string title, std::string spec) {
    this->title = title;
    this->spec = spec;
}

void Group::addStudent(Student* student) {
    this->students.push_back(student);
}

void Group::delStudent(Student* student) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->getId() == student->getId()) {
            for (int j = i + 1; j < students.size(); j++) {
                student[j - 1] = student[j];
            }
        }
    }
    students.pop_back();
}

void Group::chooseHead() {
    srand(time(NULL));
    if (students.size() != 0) {
        head = students[rand() % students.size()];
    }
}

Student* Group::getStudent_id(int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->getId() == id) {
            return students[i];
        }
    }
    return nullptr;
}

Student* Group::getStudent_fio(std::string fio) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->getFio() == fio) {
            return students[i];
        }
    }
    return nullptr;
}

double Group::getAveragemark_Gr() {
    double sum = 0.0;
    for (int i = 0; i < students.size(); i++) {
        sum += students[i]->getAveragemark();
    }
    return sum / students.size();
}

void Group::removeStudent(Student* student) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i] == student) {
            students.erase(students.begin() + i);
        }
    }
}

bool Group::isEmpty() {
    return (students.size() == 0);
}

std::string Group::getTitle() {
    return title;
}

std::string Group::getSpec() {
    return spec;
}
