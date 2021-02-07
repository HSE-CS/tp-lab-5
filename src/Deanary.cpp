// Copyright 2021 Nikolaev Ivan

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include "Group.h"
#include "Deanary.h"

Deanary::Deanary() {}

void Deanary::createGroups(std::string title, std::string spec) {
    Group* group = new Group(title, spec);
    groups.push_back(group);
}
void Deanary::hireStudents(std::string title, Student* student) {
    for (int i = 0; i < groups.size(); i++) {
        if (groups[i]->title == title) {
            groups[i]->addStudent(student);
        }
    }
}
void Deanary::addMarksToAll() {
    for (int i = 0; i < groups.size(); i++) {
        Group* group = groups[i];
        for (int j = 0; j < groups[i]->students.size(); j++) {
            group->students[j]->addmark(2 + std::rand() % 4);
        }
    }
}
std::map<int, double> Deanary::getStatistics() {
    std::map<int, double> listOfStudents;
    for (int i = 0; i < groups.size(); i++) {
        Group* group = groups[i];
        for (int j = 0; j < groups[i]->students.size(); j++) {
            double averageMark = group->students[j]->getAveragemark();
            listOfStudents[group->students[j]->id] = averageMark;
        }
    }
    return listOfStudents;
}
std::map<int, double> Deanary::getStatistics(Group *group) {
    std::map<int, double> listOfStudents;
    for (int j = 0; j < group->students.size(); j++) {
        double averageMark = group->students[j]->getAveragemark();
        listOfStudents[group->students[j]->id] = averageMark;
    }
    return listOfStudents;
}
void Deanary::moveStudents(Group* from, Group *to, Student *student) {
    from->removeStudent(student);
    to->addStudent(student);
    if (student->isHeadOfGroup()) {
        initHeads(from);
    }
}
void Deanary::saveStaff() {
    std::ofstream out;
    out.open("groups.txt");
    if (out.is_open()) {
        for (int i = 0; i < groups.size(); i++) {
            Group* group = groups[i];
            out << "Group:" << group->title << std::endl;
            out << "Spec:" << group->spec << std::endl;
            for (int j = 0; j < group->students.size(); j++) {
                out << group->students[j]->getFio() << std::endl;
            }
        }
    }
}
void Deanary::initHeads(Group* group) {
    std::cout << group->students.size() << std::endl;
    if (group->students.size() > 0) {
        group->chooseHead(
            group->students[std::rand() % group->students.size()]);
    }
}
void Deanary::fireStudents(Student* student) {
    bool fl = false;
    if (student->isHeadOfGroup()) {
        fl = true;
    }
    student->group->removeStudent(student);
    if (fl) {
        initHeads(student->group);
    }
}

void Deanary::readFile() {
    std::string line;
    std::string path("groups.txt");

    std::string title;
    std::string spec;

    std::ifstream in(path);
    if (in.is_open()) {
        while (getline(in, line)) {
            if (line.find("Group:") != -1) {
                int end = line.find('\0');
                title = line.substr(6, end - 7);
            } else if (line.find("Spec:") != -1) {
                int end = line.find('\0');
                spec = line.substr(5, end - 6);
                this->createGroups(title, spec);
            } else {
                this->IdCounter++;
                int end = line.find('\0');
                std::string fio = line.substr(0, end - 1);
                Student* student = new Student(this->IdCounter, fio);
                this->hireStudents(title, student);
            }
        }
    }
    in.close();
}

Group* Deanary::findGroup(std::string title) {
    for (int i = 0; i < groups.size(); i++) {
        if (groups[i]->title == title)
            return groups[i];
    }
    return nullptr;
}

Student* Deanary::findStudent(int id) {
    for (int i = 0; i < groups.size(); i++) {
        Group* group = groups[i];
        for (int j = 0; j < groups[i]->students.size(); j++) {
            if (group->students[j]->id == id)
                return group->students[j];
        }
    }
    return nullptr;
}

void Deanary::printStatistics(std::map<int, double> list) {
    for (auto& student : list) {
        std::cout << findStudent(student.first)->getFio() <<
            " : " << student.second << std::endl;
    }
}
