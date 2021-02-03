// Copyright 2021 BekusovMikhail

#include "Group.h"


void Group::addStudent(Student *s) {
    students.push_back(s);
    if (this != s->getGr()) {
        s->addToGroup(this);
    }
}

void Group::chooseHead(Student *h) {
    head = h;
}

double Group::getAverageMark() {
    double all(0);
    for (Student *st : students) {
        all += st->getAverageMark();
    }
    return all / students.size();
}

bool Group::containsStudent(Student *s) {
    for (Student *st : this->getStudents()) {
        if (st->getId() == s->getId()) {
            return true;
        }
    }
    return false;
}

bool Group::isEmpty() {
    return students.empty();
}

Group::Group(const std::string &t, const std::string &s) {
    title = t;
    spec = s;
}

void Group::removeStudent(Student *s) {
    s->setGr(nullptr);
    bool flag = false;
    for (int i = 0; i < this->getStudents().size(); ++i) {
        if (students[i]->getId() == s->getId()) {
            students.erase(students.begin() + i);
            flag = true;
        }
    }
    if (flag && !this->isEmpty()) {
        this->chooseHead(this->students[0]);
    } else if (this->isEmpty()) {
        this->chooseHead(nullptr);
    }
}

std::string Group::getTitle() {
    return title;
}

Student *Group::getStudent(const std::string &sid) {
    for (Student *st : this->getStudents()) {
        if (st->getId() == sid) {
            return st;
        }
    }
    return nullptr;
}

std::string Group::getSpec() {
    return spec;
}

Student *Group::getHead() {
    return head;
}

std::vector<Student *> Group::getStudents() {
    return students;
}


Group::~Group() = default;
