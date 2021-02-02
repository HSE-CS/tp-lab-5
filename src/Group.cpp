// Copyright 2021 Khoroshavina Ekaterina

#include "Group.h"

void Group::addStudent(Student* student) {
    this->students.push_back(student);
}

void Group::chooseHead() {
    srand(0);
    this->head = this->students[rand() % (this->students.size())];
}

void Group::removeStudent(Student* student) {
    int index = 0;
    for (Student* person : this->students) {
        if (person != student) {
            index++;
        }
    }
    this->students.erase(this->students.begin() + index);
    if (this->head == student) {
        this->head = nullptr;
        chooseHead();
    }
}

Group::Group(std::string name, std::string sp) {
    this->title = std::move(name);
    this->spec = std::move(sp);
}

//Group::~Group() {
//    for (Student* student : this->students) {
//        delete student;
//    }
//}

double Group::getAverageMark() {
    if (isEmpty()) {
        return 0.0;
    } else {
        double result = 0.0;
        for (Student* student : this->students) {
            result += student->getAverageMark();
        }
        return result / this->students.size();
    }
}

Student* Group::getStudent(const std::string &ident) {
    for (Student* student : this->students) {
        if (student->getFIO() == ident) {
            return student;
        }
    }
}

Student* Group::getStudent(int id) {
    for (Student* student : this->students) {
        if (student->getId() == id) {
            return student;
        }
    }
}

Student* Group::getHead() {
    return this->head;
}

std::string Group::getTitle() {
    return this->title;
}

std::string Group::getSpec() {
    return this->spec;
}

bool Group::containsStudent(std::string ident) {
    for (Student* student : this->students) {
        if (student->getFIO() == ident) return true;
    }
    return false;
}

bool Group::containsStudent(int id) {
    for (Student* student : this->students) {
        if (student->getId() == id) return true;
    }
    return false;
}

bool Group::isEmpty() {
    return this->students.empty();
}
