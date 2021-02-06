// Copyright 2021 GN
#include <Group.h>
#include <Student.h>
#include <iostream>
void Group::addStudent(Student* student) {
    students.push_back(student);
}
Student& Group::getStudent(const std::string& fio) {
    for (auto* student : students) {
        if (student->getName() == fio) {
            return *student;
        }
    }
}
Student& Group::getStudent(int id) {
    for (auto* student : students) {
        if (student->getId() == id) {
            return *student;
        }
    }
}
void Group::initHead() {
    srand(time(NULL));
    Student*st;
    st = students[rand() % students.size()];
    head = st;
}
Student& Group::getHead() {
    return *head;
}
double Group::av_mark() {
    double sum = 0;
    for (auto* student : students) {
        sum += student->avMark();
    }
    return sum / students.size();
}
void Group::delStudent(Student* st_) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->getName() == st_->getName()) {
            for (int j = i + 1; j < students.size(); j++) {
                students[j - 1] = students[j];
            }
            students.pop_back();
            break;
        }
    }
}
std::string Group::getName() {
    return title;
}
std::string Group::getSpec() {
    return spec;
}
