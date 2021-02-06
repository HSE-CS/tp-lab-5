// Copyright 2021 FOM

#include "Group.h"


void Group::student_choice_head() {
    int number = std::rand() % students.size();
    head = students[number];
}

void Group::student_remove(Student* student) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i]->student_FIO() == student->student_FIO()) {
            for (int j = i + 1; j < students.size(); j++) {
                students[j - 1] = students[j];
            }
            students.pop_back();
            break;
        }
    }
}

void Group::student_add(Student* student) {
    students.push_back(student);
    student->group = this;
}

bool Group::student_search_ID(int ID) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i]->student_ID() == ID) {
            return true;
        }
    }
    return false;
}

bool Group::student_search_FIO(std::string FIO) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->student_FIO() == FIO) {
            return true;
        }
    }
    return false;
}

double Group::mark_avarage() {
    double sum = 0;
    int count = 0;
    int res = 0;
    for (auto* student : students) {
        sum += student->student_mark_avarage();
        count++;
    }
    if (sum != 0) {
        res = sum / count;
    }
    else {
        res = 0;
    }
    return res;
}

Group::Group(std::string title, std::string spec) {
    this->title = title;
    this->spec = spec;
}

std::string Group::get_spec() {
    return spec;
}

std::string Group::get_title() {
    return title;
}