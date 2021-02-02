// Copyright 2021 soda
#include <iostream>
#include "Group.h"
#include "Deanary.h"
#include <ctime>


void Group::addStudent(Student* student) {
    students->push_back(student);
}

void Group::removeStudent(Student* student) {
    int student_index = containsStudent(*student);

    if (student_index != -1) {
        std::cout << student->getName() << " remove out of group "
            << title << "." << std::endl;
        if (student->isHeadOfGroup()) {
            chooseHead();
            std::cout << "New boss of group: "
                << getHead().getName() << std::endl;
        }
        students->erase(students->begin() + student_index);
    }
}

void Group::chooseHead() {
    srand(time(0));
    if (!isEmpty()) {
        if (head_id != -1) {
            int head_id_old = head_id;
            while (head_id == head_id_old) {
                Student& _student = *students->at(rand() % students->size());
                head = &_student;
                head_id = _student.getId();
            }
            std::cout << "In group " << title << " - new boss - "
                << head->getName() << std::endl;
        }
        else {
            while (head_id == -1) {
                Student& _student = *students->at(rand() % students->size());
                head = &_student;
                head_id = _student.getId();
            }
            std::cout << "In group " << title << " - new boss - "
                << head->getName() << std::endl;
        }
    }
}

double Group::getAverageMark() {
    double averageMark = 0;
    for (auto& student : *students) {
        averageMark += student->getAverageMark();
    }
    return averageMark / students->size();
}

Student& Group::getStudent(std::string& fio) {
    for (auto* student : *students) {
        if (student->getName() == fio) {
            return *student;
        }
    }
}

Student& Group::getStudent(int id) {
    for (auto* student : *students) {
        if (student->getId() == id) {
            return *student;
        }
    }
}

int Group::containsStudent(Student& student) {
    for (int i = 0; i < students->size(); ++i) {
        if (students->at(i)->getId() == student.getId()) {
            return i;
        }
    }
    return -1;
}

std::string Group::getTitle() {
    return title;
}

Student& Group::getHead() {
    return *this->head;
}

bool Group::isEmpty() {
    return this->students->empty();
}


std::vector<Student*>* Group::getGroupStudents() {
    return students;
}

Group::~Group() {
    for (auto student : *students) {
        delete student;
    }
    delete students;
}
