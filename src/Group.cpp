//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include <stdio.h>
#include <iostream>

#include "Group.h"
#include "Student.h"

void Group::addStudent(Student* student) {
    if (this->containsStudent(student->ID_) != -1)
        throw std::invalid_argument("student is already in this group");
    this->students_.push_back(student);
    student->addToGroup(this);
}

void Group::removeStudent(Student* student) {
    int index = this->containsStudent(student->ID_);
    if (index == -1)
        throw std::invalid_argument("no sush student in this group");
    this->students_.erase(this->students_.begin() + index);
}

void Group::chooseHead(Student* student) {
    if (this->containsStudent(student->ID_) == -1)
        throw std::invalid_argument("no such students in this group");
    this->head_ = student;
}

int Group::containsStudent(int studentID, std::string fio_) {
    if (studentID == -1 && fio_ == "")
        return -1;

    for (int i = 0; i < this->students_.size(); i++){
        if (this->students_[i]->ID_ == studentID
            || this->students_[i]->fio_ == fio_)
            return i;
    }

    return -1;
}

Student* Group::getStudent(int index, int studentID, std::string fio_) {
    int new_index = index;
    if (index == -1)
        index = this->containsStudent(studentID, fio_);

    if (new_index == -1)
        throw std::invalid_argument("no sush student in this group");

    return this->students_[new_index];
}

Student* Group::getHead() {
    if (this->isEmpty())
        return nullptr;
    if (this->head_ == nullptr)
        this->chooseHead(this->students_[0]);
    return this->head_;
}

float Group::getAverageMark() {
    float sum = 0.0;
    for (auto& st : this->students_)
        sum += st->getAverageMark();
    return sum/this->students_.size();
}

bool Group::isEmpty() {
    return this->students_.size() == 0;
}
