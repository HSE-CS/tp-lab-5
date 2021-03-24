// Copyright 2021 Tyulin Igor

#include <iostream>
#include "Group.h"

Group::Group(std::string title, std::string spec) {
    this->title = title;
    this->spec = spec;
}


void Group::sethead(Student *head) {
    this->head = head;
}

std::string Group::gethead() {
    return head->stud_fio();
}

std::string Group::getitle() {
    return title;
}

std::string Group::getspec() {
    return spec;
}

void Group::addstud(Student* stud) {
    students.push_back(stud);
}

Student* Group::findstud(int id) {
    for (auto student : students) {
        if (student->id == id) {
            return student;
        }
    }
}

Student* Group::findstud(std::string fio) {
    for (auto student : students) {
        if (student->fio == fio) {
            return student;
        }
    }
}

void Group::kickstud(Student *student) {
    for (size_t i = 0; i < students.size(); ++i) {
        if (student->id == students[i]->stud_id()) {
            students.erase(students.begin() + i);
            break;
        }
    }
}

double Group::studavermarks() {
double res = 0;
    for (auto student : students) {
        res += student->average_mark();
    }
    return res/students.size();
}
