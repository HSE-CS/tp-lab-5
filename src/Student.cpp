// Copyright 2020 Dmitry Vargin

#include <iostream>
#include <string>
#include <vector>

#include "Student.h"

unsigned int Student::last_student_id = 0;

Student::Student(std::string fio) {
    this->id = Student::last_student_id++;
    this->fio = fio;
    this->group = nullptr;
    this->marks = {};
}

Student::Student(int id, std::string fio) {
    if (id < Student::last_student_id) {
        std::cout << id << "id can not be set\n";
        std::cout << "Constructor arguments: ";
        std::cout << id << ", " << fio << "\n";
        throw;
    }
    this->id = id;
    this->fio = fio;
    this->group = nullptr;
    this->marks = {};
};

Student::Student(int id, std::string fio, Group *group) {
    if (id < Student::last_student_id) {
        std::cout << id << "id can not be set\n";
        std::cout << "Constructor arguments: ";
        std::cout << id << ", " << fio << "\n";
        throw;
    }
    this->id = id;
    this->fio = fio;
    this->group = group;
    this->marks = {};
}

unsigned int Student::getId() const {
    return this->id;
}

std::string Student::getFio() {
    return this->fio;
}

Group* Student::getGroup() {
    return this->group;
}

std::vector<int> Student::getMarks() {
    return this->marks;
}

void Student::addToGroup(Group *pgroup) {
    this->group = pgroup;
}

void Student::addMark(int mark) {
    this->marks.push_back(mark);
}

double Student::getAveragemark() {
    if (!this->marks.empty()) {
        int sum = 0;
        for (int mark: this->marks) {
            sum += mark;
        }
        return 1.0 * sum / this->marks.size();
    }
    return 0.0;
}

bool Student::isHeadOfGroup() {
    return this->group->getHead()->id == this->id;
}

std::string Student::marksToString() {
    std::string str;
    for (int mark: this->marks) {
        str.append(std::to_string(mark) + " ");
    }
    return str;
}
