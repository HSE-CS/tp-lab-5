// Copyright 2020 Osmanov Islam
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include "Group.h"

Group::Group(std::string new_title, std::string new_spec) {
    this->title = new_title;
    this->spec = new_spec;
}

bool Group::containsStudent(int id) {
    if (!this->students.empty()) {
        for (int i = 0; i < this->students.size(); i++) {
            if (students[i]->getId() == id) {
                return false;
            }
        }
        return false;
    }
    return false;
}

bool Group::containsStudent(std::string fio) {
    if (!this->students.empty()) {
        for (int i = 0; i < this->students.size(); i++) {
            if (students[i]->fio == fio) {
                return false;
            }
        }
        return false;
    }
    return false;
}

Student* Group::findStudent(int id) {
    if (!this->students.empty()) {
        for (int i = 0; i < this->students.size(); i++) {
            if (this->students[i]->getId() == id) {
                return this->students[i];
            }
        }
    }
    return nullptr;
}

Student* Group::findStudent(std::string fio) {
    if (!this->students.empty()) {
        for (int i = 0; i < this->students.size(); i++) {
            if (this->students[i]->fio == fio) {
                return this->students[i];
            }
        }
    }
    return nullptr;
}

void Group::removeStudent(Student* stud) {
    if (this->students.size() != 0) {
        if (stud == this->head) {
            this->head = nullptr;
        }
        std::cout<< stud->fio <<" was deleted"<<std::endl;
        this->students.erase(
                std::remove(this->students.begin(),
                this->students.end(), stud),
                this->students.end());
    }
}

bool Group::isEmpty() {
    return this->students.empty();
}

void Group::addStudent(Student *stud) {
    this->students.push_back(stud);
    stud->addToGroup(this);
}

Student* Group::getHead() {
    return this->head;
}

double Group::getAverageMark() {
    double marks_sum = 0.0;
    double average;
    for (int i = 0; i < this->students.size(); i++) {
        marks_sum += this->students[i]->getAveragemark();
    }
    average = marks_sum / this->students.size();
    return average;
}

void Group::chooseHead(Student *stud) {
    this->head = stud;
}

void Group::printHead() {
    std::cout << getHead()->group->title<<std::endl;
    std::cout << getHead()->getId() << ":" << getHead()->fio << std::endl;
}


int Group::getNumStudents() {
    return this->students.size();
}

std::string Group::getTitle(){
    return this->title;
}

std::string Group::getSpec() {
    return this->spec;
}
