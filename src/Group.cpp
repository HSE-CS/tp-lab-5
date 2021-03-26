// Copyright Mushka Nikita, 2021

#include "../include/Group.h"
#include <../include/Student.h>


// КОНСТРУКТОРЫ //

Group::Group(std::string new_title, std::string new_spec) {
    this->title = std::move(new_title);
    this->spec = std::move(new_spec);
}


// ОСНОВНЫЕ МЕТОДЫ //

void Group::AddStudent(Student *student_toAdd) {
    students.push_back(student_toAdd);
}

void Group::RemoveStudent(Student *student_toRemove) {
    int toRemove_id = student_toRemove->id;
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->id == toRemove_id) {
            students.erase(students.begin() + i);
            break;
        }
    }
}

void Group::ChooseLeader(Student *new_head) {
    leader = new_head;
}

float Group::CountAvgMark() {
    float sum = 0;
    unsigned int len = students.size();

    for (int i = 0; i < len; i++) {
        sum += students[i]->CountAvgMark();
    }

    return sum / static_cast<float>(len);
}


// ВОЗВРАЩАЛКИ //

Student *Group::GetById(int id_toFind) {
    for (auto &student : students) {
        if (student->id == id_toFind) {
            return student;
        }
    }
    return nullptr;
}

Student *Group::GetByFio(const std::string &fio_toFind) {
    for (auto &student : students) {
        if (student->fio == fio_toFind) {
            return student;
        }
    }
    return nullptr;
}


// ВОЗВРАЩАЛКИ ПОПРОЩЕ //

std::string Group::GetTitle() {
    return title;
}

std::string Group::GetSpec() {
    return spec;
}

Student *Group::GetLeader() {
    return leader;
}

bool Group::IsEmpty() {
    return students.empty();
}

