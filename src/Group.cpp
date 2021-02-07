#include "Group.h"

Group::Group(std::string title, std::string spec) {
    this->title = title;
    this->spec = spec;
}

double Group::getAveragemark() {
    double sum = 0.0;
    for (int i = 0; i < students.size(); i++) {
        sum += students[i]->getAveragemark();
    }
    return sum;
}

Student* Group::getStudent(int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->getId() == id) {
            return students[i];
        }
    }
    return new Student;
}

Student* Group::getStudent(std::string fio) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->getFio() == fio) {
            return students[i];
        }
    }
    return new Student;
}

bool Group::containsStudent(int id) {
    Student* student = getStudent(id);
    if (student->getId() == -1) {
        return false;
    } else {
        return true;
    }
}

bool Group::containsStudent(std::string fio) {
    Student* student = getStudent(fio);
    if (student->getId() == -1) {
        return false;
    } else {
        return true;
    }
}

bool Group::isEmpty() {
    if (students.size() == 0) {
        return true;
    } else {
        return false;
    }
}

void Group::addStudent(Student* student) {
    student->addToGroup(this);
    students.push_back(student);
}

void Group::chooseHead(Student* student) {
    head = student;
}

void Group::removeStudent(Student* student) {
    student->group = NULL;
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->id == student->id) {
            students.erase(students.begin() + i);
        }
    }
}