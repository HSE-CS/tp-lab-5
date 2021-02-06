// Copyright 2021 Khoroshavina Ekaterina

#include "Deanary.h"
#include <sstream>
#include <fstream>

Deanary::Deanary() {
    this->num_gr = 0;
}

// Deanary::~Deanary() {
//     for (Group* group : this->groups) {
//         group->~Group();
//     }
// }

void Deanary::createGroup(std::string name, std::string sp) {
    Group group(name, sp);
    this->groups.push_back(&group);
}

void Deanary::addGroup(Group* group) {
    this->groups.push_back(group);
}

void Deanary::hireStudents(Group* group, std::string fio) {
    int id = group->students.size() + 1;
    Student student(id, fio, group);
    group->addStudent(&student);
}

void Deanary::addMarksToAll(int mark) {
    for (Group* group : this->groups) {
        for (Student* student : group->students) {
            student->addMark(mark);
        }
    }
}

void Deanary::getStatistics() {
    std::cout << "=====Statistics:=====\n";
    for (Group* group : this->groups) {
        std::cout << "Title: " << group->getTitle() << "  Spec: "
            << group->getSpec() << std::endl;
        std::cout << "Average mark of group: "
            << group->getAverageMark() << std::endl;
        std::cout << "Head of group: " << group->getHead()->getFIO()
            << ". Id: " << group->getHead()->getId() << std::endl;
        std::cout << "Students:" << std::endl;
        for (Student* student : group->students) {
            std::cout << student->getFIO() << ". Id: " << student->getId()
                << ". Average mark: " << student->getAverageMark() << std::endl;
        }
        std::cout << "==========" << std::endl;
    }
}

void Deanary::moveStudent(Group* fromGroup, Group* toGroup, Student* student) {
    fromGroup->removeStudent(student);
    toGroup->addStudent(student);
}

void Deanary::fireStudents(int lowMark) {
    for (Group* group : this->groups) {
        for (Student* student : group->students) {
            if (student->getAverageMark() < lowMark) {
                group->removeStudent(student);
            }
        }
    }
}

void Deanary::saveStaff() {
    std::ofstream out;
    out.open("Statistics.txt");
    if (out.is_open()) {
        out << "Statistics:\n";
        for (Group* group : this->groups) {
            out << "Title: " << group->getTitle() << "  Spec: "
                << group->getSpec() << std::endl;
            out << "Average mark of group: "
                << group->getAverageMark() << std::endl;
            out << "Head of group: " << group->getHead()->getFIO()
                << " " << group->getHead()->getId() << std::endl;
            out << "Students:" << std::endl;
            for (Student* student : group->students) {
                out << student->getFIO() << " " << student->getId()
                    << ". Average mark: " << student->getAverageMark()
                    << std::endl;
            }
            out << "==========" << std::endl;
        }
    }
    out.close();
}

void Deanary::initHeads() {
    for (Group* group : this->groups) {
        group->chooseHead();
    }
}

void Deanary::initHeadsIfNone() {
    for (Group* group : this->groups) {
        if (group->head == nullptr) {
            group->chooseHead();
        }
    }
}

std::vector<Group*>& Deanary::getGroups() {
    return this->groups;
}
