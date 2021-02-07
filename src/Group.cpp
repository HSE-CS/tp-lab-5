// Copyright 2021 Sozinov Kirill
#include "Group.h"
#include "Student.h"
#include <time.h>
#include <cstdlib>


Group::Group(std::string title, std::string spec) {
    this->title = title;
    this->spec = spec;
    this->head = nullptr;
}

Group::~Group() {
    delete this;
}

void Group::addStudent(Student *st) {
    students.push_back(st);
    if (students.size() == 1)
        chooseHead();
    st->group = this;
}

void Group::chooseHead() {
    srand(time(NULL));
    if (head) {
        head->isHead = false;
        head = nullptr;
    }
    unsigned choose = std::rand() % (students.size() - 1);
    this->head = students[choose];
    students[choose]->isHead = true;
}

Student *Group::getHead() {
    return this->head;
}

Student *Group::getStudent(std::string fio) {
    for (int i = 0; i < students.size(); ++i)
        if (fio == (*students[i]).getFIO())
            return students[i];
    throw "There's no such student";
}

Student *Group::getStudent(unsigned id) {
    for (int i = 0; i < students.size(); ++i)
        if (id == (*students[i]).getID())
            return students[i];
    throw "There's no such student";
}

bool Group::containsStudent(unsigned id) {
    for (int i = 0; i < students.size(); ++i) {
        if (id == (*students[i]).getID())
            return true;
    }
    return false;
}

bool Group::containsStudent(std::string fio) {
    for (int i = 0; i < students.size(); ++i) {
        if (fio == (*students[i]).getFIO())
            return true;
    }
    return false;
}

double Group::getAverageMark() {
    double sum = 0;
    for (int i = 0; i < students.size(); ++i) {
        sum += (*students[i]).getAverageMark();
    }
    return sum / students.size();
}

void Group::removeStudent(Student *st) {
    int ind = -1;
    for (int i = 0; i < students.size(); ++i) {
        if (st->getID() == students[i]->getID()) {
            ind = i;
            continue;
        }
    }
    if (ind == -1) {
        return;
    } else {
        students.erase(students.begin() + ind);
        st->group = nullptr;
    }
}

std::vector <Student *> Group::getStudents() const {
    return students;
}
