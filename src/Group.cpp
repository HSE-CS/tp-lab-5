// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 06.02.2021.
//
#include <algorithm>
#include <utility>
#include "Group.h"

Group::Group(std::string valSpec, int valTitle) {
    this->spec = std::move(valSpec);
    this->title = valTitle;
    this->head = nullptr;
}

double Group::getAvrMark() const {
    double result = 0;
    for (auto s : students)
        result += s->getAvrMark();
    if (students.empty()) {
        return 0;
    } else {
        return result / students.size();
    }
}

Student *Group::getStudent(unsigned int id) const {
    Student *result = nullptr;
    for (auto s : students)
        if (s->id == id)
            result = s;
    return result;
}

Student *Group::getStudent(const std::string &name) const {
    Student *result = nullptr;
    for (auto s : students)
        if (s->fio == name)
            result = s;
    return result;
}

void Group::addStudent(Student *s) {
    students.push_back(s);
    s->group = this;
}

bool Group::containsStudent(unsigned int id) const {
    return getStudent(id) != nullptr;
}

bool Group::isEmpty() const {
    return students.empty();
}

bool Group::containsStudent(const std::string &name) const {
    return getStudent(name) != nullptr;
}

void Group::chooseHead() {
    if (!students.empty()) {
        int headId = rand() % students.size();
        head = students[headId];
        students[headId]->addHead();
    }
}

Student *Group::createStudent(unsigned int id, std::string name) {
    return students.emplace_back(new Student(id, std::move(name), this));
}

void Group::removeStudent(Student *s) {
    auto n = std::find(students.begin(), students.end(), s);
    if (n != students.end())
        students.erase(n);
    if (s->isHead) {
        chooseHead();
    }
    s->group = nullptr;
}

int Group::getGSize() {
    return students.size();
}

std::string Group::getSpec() const {
    return this->spec;
}

unsigned int Group::getTitle() const {
    return this->title;
}

