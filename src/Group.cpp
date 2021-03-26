// Copyright 2021 Bekina Svetlana
#include "Group.h"
#include "Student.h"

Group::Group() {}
Group::~Group() {
    students.clear();
}
Group::Group(std::string new_title, std::string new_spec) {
    title = new_title;
    spec = new_spec;
}
void Group::addStudent(Student* student) {
    students.push_back(student);
}

double Group::getAveragemark() {
    if (!isEmpty()) {
        double averagemark = 0;
        for (auto student : students) {
            averagemark += student->getAveragemark();
        }
        return averagemark / students.size();
    } else {
        std::cout << "В этой группе нет студентов\n";
    }
}

Student* Group::getStudent(std::string param) const {
    if (!isEmpty()) {
        for (auto student : students) {
            if (student->getId() == param || student->getFio() == param) {
                return student;
            }
        }
        std::cout << "Извините, студента " << param << " нет в этой группе." << std::endl;
    } else {
        std::cout << "В этой группе нет студентов\n";
    }
}

bool Group::containsStudent(std::string param) const {
    if (!isEmpty()) {
        for (auto student : students) {
            if (student->getId() == param || student->getFio() == param) {
                return true;
            }
        }
        return false;
    } else {
        std::cout << "В этой группе нет студентов\n";
    }
}

void Group::removeStudent(std::string id) {
    if (!isEmpty()) {
        size_t index = -1;
        for (size_t i = 0; i < students.size(); i++) {
            if (students[i]->getId() == id) {
                index = i;
            }
        }
        if (index != -1) {
            if (students[index]->isHeadOfGroup()) {
                students.erase(students.begin() + index);
                chooseHead();
            }
            else {
                students.erase(students.begin() + index);
            }
        }
    } else {
        std::cout << "В этой группе нет студентов\n";
    }
}

bool Group::isEmpty() const {
    if (students.size() == 0) {
        return true;
    } else {
        return false;
    }
}

std::string Group::getTitle() const {
    return title;
}

std::vector<Student*> Group::getStudents() const {
    return students;
}

void Group::chooseHead() const {
    head = students[rand() % students.size()];
}

Student* Group::getHead() const {
    return head;
}
