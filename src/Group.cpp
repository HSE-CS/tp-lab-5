// Copyright [2021] <Nikita Semaev>
#include <vector>
#include <algorithm>
#include "../include/Student.h"
#include "../include/Group.h"

//class Student;
//class Group;

Student* Group::findStudent(const uint16_t id) {
    Student *result = nullptr;
    for (auto student : this->students) {
        if (student->id == id) {
            result = student;
            break;
        }
    }
    return result;
}

Student* Group::findStudent(const std::string fio) {
    Student *result = nullptr;
        for (auto student : this->students) {
            if (student->fio == fio) {
                result = student;
                break;
            }
        }
        return result;
}

bool Group::isExist(Student *student) {
    auto element = std::find(students.begin(), students.end(), student);
    return element != students.end();
}

void Group::addStudent(Student *student) {
    if (!this->isExist(student)) {
        this->students.push_back(student);
    }
}

void Group::setHead(Student *student) {
    if (this->isExist(student)) {
        this->head = student;
    }
}

float Group::averageMark() const {
    float &&result = 0;
    for (auto student : this->students) {
        result += student->averageMark();
    }
    result /= this->students.size();
    return result;
}

void Group::excludeStudent(Student *student) {
    std::remove(this->students.begin(), this->students.end(), student);
}

const std::vector <Student *> &Group::getStudents() const {
    return this->students;
}

const std::string &Group::getTitle() const {
    return this->title;
}
