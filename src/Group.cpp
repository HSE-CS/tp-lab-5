// Copyright 2021 soda

#include <iostream>
#include <Deanary.h>
#include <Group.h>


void Group::addStudent(Student& student) {
    students->push_back(&student);
}
//
//void Group::removeStudent(Student& student) {
//    int student_index = containsStudent(student);
//    if (-1 != student_index) {
//        std::cout << student.getName() << " ������ �� ������ \""
//            << title << "\"." << std::endl;
//        if (student.isHeadOfGroup()) {
//            chooseHead(student.getId(), false);
//            std::cout << "����� �������� ������: "
//                << getHead().getName() << std::endl;
//        }
//        students->erase(students->begin() + student_index);
//
//    }
//}
//
//void Group::chooseHead(int oldHeadId, bool silence) {
//    if (!isEmpty()) {
//        do {
//            Student& st = *students->at(deanery->rand_int() % students->size());
//            head = &st;
//        } while (head->getId() == oldHeadId);
//        if (!silence) {
//            std::cout << "� ������ \"" << title << "\" ��������� ��������(�) "
//                << head->getName() << std::endl;
//        }
//    }
//}

//double Group::getAverageMark() {
//    double averageMark = 0;
//    for (auto& student : *students) {
//        averageMark += student->getAverageMark();
//    }
//    return averageMark / students->size();
//}

//Student& Group::getStudent(const std::string& fio) {
//    for (auto* student : *students) {
//        if (student->getName() == fio) {
//            return *student;
//        }
//    }
//}

//Student& Group::getStudent(int id) {
//    for (auto* student : *students) {
//        if (student->getId() == id) {
//            return *student;
//        }
//    }
//}
//
//int Group::containsStudent(Student& student) {
//    for (int i = 0; i < students->size(); i++) {
//        if (students->at(i)->getId() == student.getId()) {
//            return i;
//        }
//    }
//    return -1;
//}

std::string Group::getTitle() {
    return title;
}

Student& Group::getHead() {
    return *this->head;
}

bool Group::isEmpty() {
    return this->students->empty();
}

Group::~Group() {
    for (auto student : *students) {
        delete student;
    }
    delete students;
}