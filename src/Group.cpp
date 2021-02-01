// Copyright by JMax 2020

#include "Group.h"


Group::Group(const std::string &title, const std::string &spec) {
    this->title = title;
    this->spec = spec;
    this->students = std::vector<Student*>();
}

void Group::addStudent(Student *student) {
    students.push_back(student);
    student->group = this;
}

void Group::chooseHead() {
    if (!isEmpty()) {
        int index = std::rand() % numOfStudents();
        head = students[index];
    }
}

unsigned int Group::numOfStudents() const {
    return students.size();
}

void Group::removeStudent(Student *student) {
    removeStudent(student->getId());
}

void Group::removeStudent(unsigned int id) {
    if (containsStudent(id)) {
        unsigned int index = studentIndex(id);
        Student* student = getStudent(id);

        student->removeFromGroup();
        students.erase(students.begin() + index);

        if (student == getHead()) {
            chooseHead();
        }
    }
}

void Group::removeStudent(const std::string& fio) {
    Student* student = getStudent(fio);
    removeStudent(student->getId());
}

int Group::studentIndex(unsigned int id) const {
    for (int i = 0; i < numOfStudents(); i++) {
        if (id == students[i]->getId()) {
            return i;
        }
    }
    return -1;
}

int Group::studentIndex(const std::string& fio) const {
    for (int i = 0; i < numOfStudents(); i++) {
        if (fio == students[i]->getFio()) {
            return i;
        }
    }
    return -1;
}

double Group::getAverageMark() const {
    double sum = 0;
    for (auto student : students) {
        sum += student->getAverageMark();
    }
    return sum / numOfStudents();
}

Student *Group::getStudent(unsigned int id) const {
    if (containsStudent(id)) {
        return students[studentIndex(id)];
    }
    throw "No student found";
}

Student *Group::getStudent(const std::string &fio) const {
    if (containsStudent(fio)) {
        return students[studentIndex(fio)];
    }
    throw "No student found";
}

bool Group::containsStudent(unsigned int id) const {
    return studentIndex(id) != -1;
}

bool Group::containsStudent(const std::string &fio) const {
    return studentIndex(fio) != -1;
}

bool Group::isEmpty() const {
    return numOfStudents() == 0;
}

Student *Group::getHead() const {
    return head;
}

Group::~Group() {
    for (auto student : students) {
        delete student;
    }
}

void Group::setHead(const std::string &fio) {
    head = getStudent(fio);
}
