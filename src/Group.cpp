//
// Created by toliman on 03.02.2021.
//

#include "../include/Group.h"

#include "Student.h"


Group::Group(std::string titleParam) {
    this->title = std::move(titleParam);
    this->head = nullptr;
}

std::string Group::getTitle() {
    return this->title;
}

void Group::setTitle(std::string titleParam) {
    this->title = std::move(titleParam);
}

void Group::setSpec(std::string specParam) {
    this->spec = std::move(specParam);
}

void Group::addStudent(Student &student) {
    this->students.push_back(&student);
}

void Group::chooseHead() {
    std::random_device generator;
    this->head = this->students[generator() % this->students.size()];
}

Student *Group::searchStudent(const std::string &fioField) {
    for (auto s : this->students) {
        if (s->getFio() == fioField)
            return s;
    }
    return nullptr;
}

Student *Group::searchStudent(int idField) {
    for (auto s : students) {
        if (s->getId() == idField)
            return s;
    }
    return nullptr;
}
