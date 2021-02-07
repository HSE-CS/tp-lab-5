// Copyright 2021 kostinandrey

#include "Group.h"
#include <utility>
#include <numeric>

Group::Group(std::string title, std::string spec) {
    this->title = std::move(title);
    this->spec = std::move(spec);
}

std::string Group::get_title() {
    return title;
}

std::string Group::get_spec() {
    return spec;
}

void Group::add_student(Student* student) {
    students.push_back(student);
    student->group = this;
}

void Group::remove_student(Student* student) {
    for (size_t index = 0; index < students.size(); ++index) {
        if (student->id == students[index]->get_id()) {
            students.erase(students.begin() + index);
            break;
        }
    }
}

void Group:: choose_head(){
    if (!students.empty()) {
        head = students[std::rand() % students.size()];
    }
}
std::string Group:: search_student(int search_id){
    for (auto* student : students) {
        if (student->id == search_id)
            return student->get_fio();
    }

    return "Not found";

}

bool Group::search_student(const std::string& search_fio) {
    for (auto* student : students)
        if (student->fio == search_fio) return true;
    return false;
}

double Group::average_mark_group() {
    double sum = 0;
    for (auto* student : students)
        sum += student->get_average_mark();
    if (!students.empty())
        return sum/students.size();
    return 0;
}
