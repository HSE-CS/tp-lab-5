// Copyright 2021 Bodrov Egor

#include "Group.h"
#include "Student.h"

Group::Group(const std::string& title_, const std::string& spec_)
    : title {title_}, spec {spec_}
{
}

void Group::addStudent(Student* student) {
    students.push_back(student);
    student->addToGroup(this);
}

void Group::chooseHead(Student* student) {
    if (isEmpty() == false) {
        head = student;
    }
}

void Group::removeStudent(Student* student) {
    if (student == head)
        head = nullptr;
    for (int i = 0; i < students.size(); i++) {
        if (students[i] == student) {
            students.erase(students.begin() + i);
        }
    }
}

double Group::getAveragemark() {
    if (isEmpty() == true) {
        return 0;
    }
    double res {0.0};
    for (auto i : students) {
        res += i->getAveragemark();
    }
    return static_cast <double> (res / students.size());
}

Student* Group::getStudent(int id) {
    for (auto i : students) {
        if (i->get_id() == id)
            return i;
    }
    return nullptr;
}

Student* Group::getStudent(const std::string& name) {
    for (auto i : students) {
        if (i->get_name() == name)
            return i;
    }
    return nullptr;
}

bool Group::isEmpty() {
    return students.size() < 1;
}
