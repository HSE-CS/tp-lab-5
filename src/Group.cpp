// Copyright 2020 Dmitry Vargin

#include <string>
#include <cstring>
#include <vector>

#include "Group.h"

Group::Group(std::string title) {
    this->title = title;
}

void Group::addStudent(Student *student) {
    this->students.push_back(student);
    student->addToGroup(this);
}

void Group::chooseHead(Student *phead) {
    this->head = phead;
}

Student *Group::getStudent(int student_id) {
    for (Student *student : this->students) {
        if (student->getId() == student_id) {
            return student;
        }
    }
    return nullptr;
}

Student *Group::getStudent(std::string student_fio) {
    for (Student *student : this->students) {
        if (!strcmp(student->getFio().c_str(), student_fio.c_str())) {
            return student;
        }
    }
    return nullptr;
}

double Group::getAveragemark() {
    if (!this->students.empty()) {
        double sum = 0;
        for (Student *student : this->students) {
            sum += student->getAveragemark();
        }
        return sum / this->students.size();
    }
    return 0.0;
}

bool Group::containsStudent(Student *student) {
    for (Student *iter : this->students) {
        if (iter == student)
            return true;
    }
    return false;
}

void Group::removeStudents(Student *student) {
    for (int i = 0; i < this->students.size(); ++i) {
        if (this->students[i] == student) {
            this->students.erase(this->students.begin()+i);
            return;
        }
    }
}

bool Group::isEmpty() {
    return this->students.empty();
}

Student *Group::getHead() {
    return this->head;
}

std::string Group::getTitle() {
    return this->title;
}

std::vector<Student*> Group::getStudents() {
    return this->students;
}
