// Copyright 2021 Tatsenko Ilya
#include <iostream>
#include<vector>
#include "Group.h"


std::string Group::get_header() {
        return head->get_fio();
    }
std::string Group::get_students() {
        return students[0]->fio;
    }

void Group::add_student(Student* student) {
    this->students.push_back(student);
}

void Group::choose_header(Student* student) {
    this->head = student;
}

Student* Group::find_of_student(std::string name, int id) {
    for (int i = 0; this->students.size(); i++) {
        if (students[i]->fio == name || students[i]->id == id) {
            return students[i];
        }
    }
}

double Group::calculate_of_avarage_mark() {
    double sum = 0;
    for (int i = 0; i < this->students.size(); i++) {
        sum += this->students[i]->get_avarage_mark();
    }
    return sum / students.size();
}

void Group::remove_student(Student* st) {
    if (head == st) head = nullptr;
    for (int j = 0; j < this->students.size(); j++) {
        if (students[j]->id == st->id && students[j]->fio == st->fio) {
            students.erase(students.begin() + j);
            break;
        }
    }
}
