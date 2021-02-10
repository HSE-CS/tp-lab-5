// copyright Toliman 2021

#include "../include/Group.h"

#include "../include/Student.h"


Group::Group(std::string titleParam) {
    this->title = std::move(titleParam);
    this->head = nullptr;
}

std::string Group::getTitle() {
    return this->title;
}

void Group::setTitle(std::string titleParam) {
    this->title = std::move(titleParam);
}

void Group::setSpec(std::string specParam) {
    this->spec = std::move(specParam);
}

void Group::addStudent(Student &student) {
    this->students.push_back(&student);
    student.setGroup(*this);
}

void Group::chooseHead() {
    std::random_device generator;
    this->head = this->students[generator() % this->students.size()];
}

Student *Group::searchStudent(const std::string &fioField) {
    for (auto s : this->students) {
        if (s->getFio() == fioField)
            return s;
    }
    return nullptr;
}

Student *Group::searchStudent(int idField) {
    for (auto s : this->students) {
        if (s->getId() == idField)
            return s;
    }
    return nullptr;
}

float Group::getMiddleMark() {
    float middle(.0);
    for (auto s : students) {
        middle += s->getMiddleMark();
    }
    if (!(this->students.empty()))
        middle /= (float) (this->students.size());
    return middle;
}

void Group::deleteStudent(Student &student) {
    int index = 0;
    for (auto s : this->students) {
        if (s->getId() == student.getId()) {
            this->students.erase(this->students.begin() + index);
            s->leaveGroup();
            return;
        }
        index++;
    }
}

void Group::str() {
    std::string out = "==========\nGroup: " + this->getTitle() + '\n';
    for (auto s : this->students) {
        if (s == this->getHead()) {
            out += "<super> ";
        }
        out += s->getFio() + '\n';
    }
    out += "==========\n";
    std::cout << out;
}

std::vector<Student *> Group::getStudents() {
    return this->students;
}

void Group::setFileName(std::string file) {
    this->fileName = std::move(file);
}

std::string Group::getFileName() {
    return this->fileName;
}

Student *Group::getHead() {
    return this->head;
}
