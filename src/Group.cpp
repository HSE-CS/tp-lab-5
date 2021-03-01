// Copyright [2021] <Ziganshin Nikita>
#include "Group.h"

Group::Group(std::string title) {
    this->title = title;
}

void Group::AddStudent(const Student &student) {
    bool error = false;
    for (auto &i : students) {
        if (i.id != student.id) {
            continue;
        }
        else {
            error = true;
            std::cout
            << "There is a student with the same ID. Change student's ID";
        }
    }
    if (!error) {
        students.emplace_back(student);
        students.back().group = this;
    }
}

Student *Group::FindStudent(const std::string &fio) {
    for (auto &student : students) {
        if (student.fio == fio) {
            return &student;
        }
    }
    throw "There is no student with such name";
}

Student *Group::FindStudent(int id) {
    for (auto &student : students) {
        if (student.id == id) {
            return &student;
        }
    }
    throw "There is no student with such ID";
}

double Group::CalcAverageMarkInGroup() {
    double average = 0;
    for (auto &student : students) {
        average += student.CalcAverageMark();
    }
    average = average / students.size();
    return average;
}

void Group::KickStudent(Student *student) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == student->id) {
            students.erase(students.begin() + i);
        }
    }
    student->group = nullptr;
}

std::string Group::getTitle() const {
    return title;
}

void Group::setTitle(const std::string &title) {
    this->title = title;
}

const std::string &Group::getSpec() const {
    return spec;
}

void Group::setSpec(const std::string &spec) {
    this->spec = spec;
}

Student *Group::getHead() const {
    return head;
}

void Group::setHead(Student *head) {
    this->head = head;
}

std::vector<Student> *Group::getStudents() {
    return &students;
}

Group::~Group() {
    students.clear();
}
