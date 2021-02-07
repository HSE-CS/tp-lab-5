// Copyright 2021 tatsenko Ilya
#include<iostream>
#include<vector>
#include"Student.h"
#include"Group.h"

std::string Student::get_fio() {
    return this->fio;
}

int Student::get_id() {
    return this->id;
}

std::string Student::get_group() {
    return group->title;
}

void Student::add_to_group(Group * group) {
    this->group = group;
    group->add_student(this);
}

void Student::add_mark(int mark) {
    this->marks.push_back(mark);
}

double Student::get_avarage_mark() {
    double sum = 0;
    for (int i = 0; i < this->marks.size(); i++) {
        sum += this->marks[i];
    }
    return sum / marks.size();
}
