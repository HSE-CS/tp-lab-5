// Copyright 2020 Uskova
#include <iostream>
#include <random>
#include <stdlib.h>
#include "Group.h"

Group::Group() {
    this->title = "";
    this->spec = "";
    this->head = nullptr;
}

Group::Group(std::string title) {
    this->title = title;
    this->spec = "";
    this->head = nullptr;
}

Group::Group(std::string title, std::string spec) {
    this->title = title;
    this->spec = spec;
    this->head = nullptr;
}

Student* Group::getHead() {
    return this->head;
}

void Group::addStudent(Student* st) {
    this->students.push_back(st);
    st->addToGroup(this);
}

Student* Group::chooseRandHead() {
    srand(time(0));
    int num = 0;
    if (this->students.size() != 0) {
        num = std::rand() % this->students.size();
        this->head = this->students.at(num);
    }
    return this->head;
}

void Group::chooseHead(Student* st) {
    if ((this->students.size() != 0) && this->containsStudent(st)) {
    this->head = st;
    }
}

void Group::removeStudent(Student* st) {
    if (this->containsStudent(st)) {
        for (int i = 0; i < this->students.size(); i++) {
            if (this->students[i] == st) {
                this->students.erase(this->students.begin() + i);
                break;
            }
        }
    }
}


Student* Group::getStudent(int id) {
    if (this->students.size() != 0) {
        for (int i = 0; i < students.size(); i++) {
            if (this->students.at(i)->id == id) {
                return this->students.at(i);
                break;
            }
        }
    }
    return nullptr;
}

Student* Group::getStudent(std::string fio) {
    if (this->students.size() != 0) {
        for (int i = 0; i < students.size(); i++) {
            if (this->students.at(i)->fio == fio) {
                return this->students.at(i);
                break;
            }
        }
    }
}

float Group::getAverageMark() {
    if (this->students.size() != 0) {
        float sum = 0.0;
        for (int i = 0; i < this->students.size(); i++) {
            sum += this->students[i]->getAverageMark();
        }
        return sum / this->students.size();
    }
    return 0;
}

bool Group::containsStudent(Student* st) {
    if (this->students.size() != 0) {
        for (int i = 0; i < students.size(); i++) {
            if (this->students[i] == st) {
                return true;
            }
        }
    }
    return false;
}

bool Group::isEmpty() {
    if (this->students.size() != 0) {
        return false;
    }
    return true;
}
