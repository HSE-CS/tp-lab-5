// Copyright 2021 Shatilov Victor

#include "Group.h"

#include <utility>

Group::Group(std::string ti, std::string sp) :
title(std::move(ti)), spec(std::move(sp)) {}

void Group::addStudent(Student *student) {
    student->addToGroup(this);
    students.push_back(student);
}

void Group::chooseHead(Student* student) {
    head = student;
}

std::string Group::getTitle() { return title; }
std::string Group::getSpec() { return spec; }
Student* Group::getHead() { return head; }



Student *Group::getStudentByFio(std::string student_name) {
    for (Student *st : students) {
        if (st->fio == student_name) {
            return st;
        }
    }
    return nullptr;
}

Student* Group::getStudentById(int student_id) {
    for (Student *st : students) {
        if (st->id == student_id) {
            return st;
            break;
        }
    }
    return nullptr;
}

void Group::kickStudent(Student* student) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->id == student->id) {
            students.erase(students.begin() + i);
            break;
        }
    }
    if (head && head->id == student->id)
        head = nullptr;
}

bool Group::isEmpty() { return students.empty(); }

float Group::getAverageMark() {
    if (students.empty())
        return 0;

    float sum = 0;
    for (Student *st : students)
        sum += st->getAverageMark();

    return sum / students.size();
}
