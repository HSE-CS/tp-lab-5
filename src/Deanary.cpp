// Copyright 2021 Sozinov Kirill
#include "Deanary.h"
#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>

Deanery::Deanery() {
    groups = new std::vector<Group *>();
    createStudents();
    createGroups();
    hireStudents();
}

void Deanery::createStudents() {
    std::ifstream in("D:\\Projects_C_C++\\tp-lab5\\tp-lab5\\students.txt");
    std::string line;
    size_t i = 1;
    if (in.is_open()) {
        while (getline(in, line)) {
            this->unalloc.push_back(std::make_pair(i, line));
            i++;
        }
    }
    in.close();
}

std::stringbuf Deanery::getAllStudents() {
    std::stringbuf str;
    std::ostream stream(&str);
    for (unsigned i = 0; i < unalloc.size(); ++i) {
        stream << unalloc[i].first << '\t' << unalloc[i].second << '\n';
    }
    return str;
}

void Deanery::printAllStudents() {
    std::cout << getAllStudents().str();
}

void Deanery::createGroups() {
    std::ifstream in("D:\\Projects_C_C++\\tp-lab5\\tp-lab5\\groups.txt");
    std::string line1, line2;
    size_t i = 0;
    if (in.is_open()) {
        while (getline(in, line1) && getline(in, line2)) {
            Group *gr_ptr = new Group(line1, line2);
            groups->push_back(gr_ptr);
            i++;
        }
    }
    in.close();
}

std::string Deanery::getNameOfGroup(Group *group) {
    return (group->title + '\t' + group->spec);
}

std::stringbuf Deanery::getNameOfGroups() {
    std::stringbuf str;
    std::ostream stream(&str);
    for (auto &group : *groups) {
        stream << getNameOfGroup(group) << '\n';
    }
    return str;
}

void Deanery::hireStudents() {
    size_t sizeOfGroup = unalloc.size() / groups->size();
    for (auto &group : *groups) {
        for (size_t i = 0; i < sizeOfGroup; ++i) {
            Student *st_ptr = new Student(unalloc[0].first, unalloc[0].second);
            group->students.push_back(st_ptr);
            st_ptr->addToGroup(group);
            unalloc.erase(unalloc.begin());
        }
    }
    while (!unalloc.empty()) {
        Student *st_ptr = new Student(unalloc[0].first, unalloc[0].second);
        (*groups)[groups->size() - 1]->students.push_back(st_ptr);
        st_ptr->addToGroup((*groups)[groups->size() - 1]);
        unalloc.erase(unalloc.begin());
    }
    initHeads();
}

std::stringbuf Deanery::getGroupsWithStudents() {
    std::stringbuf str;
    std::ostream stream(&str);
    for (auto &group : *groups) {
        stream << group->title << '\t' << group->spec << ':' << '\n';
        for (auto &student : group->students) {
            stream << student->id << ": " << student->fio << '\n';
        }
        stream << '\n';
    }
    return str;
}

void Deanery::printGroups() {
    std::cout << getGroupsWithStudents().str();
}

void Deanery::addMarksToAll() {
    srand(time(NULL));
    for (auto &group : *groups) {
        for (auto &student : group->students) {
            for (size_t i = 4; i < (std::rand() % 10 + 5); ++i) {
                student->addmark(std::rand() % 5 + 2);
            }
        }
    }
}

std::stringbuf Deanery::makeStatistics() {
    std::stringbuf str;
    std::ostream stream(&str);
    stream << "Average marks:" << '\n';
    for (auto &group : *groups) {
        stream << group->title << ": " << group->getAverageMark() << '\n';
    }
    stream << '\n';
    return str;
}

void Deanery::printStatistics() {
    std::cout << makeStatistics().str();
}

void Deanery::moveStudents(std::vector<Student *> moving, Group *group) {
    for (auto &student : moving) {
        Student *temp = student;
        student->getGroup()->removeStudent(student);
        group->addStudent(temp);
    }
}

Group *Deanery::getGroup(size_t ind) {
    return (*groups)[ind];
}

void Deanery::fireStudents(double min_avg) {
    for (auto &group : *groups) {
        for (auto &student : group->students) {
            if (student->getAverageMark() <= min_avg) {
                if (student->isHeadOfGroup())
                    group->chooseHead();
                group->removeStudent(student);
            }
        }
    }
}

void Deanery::saveStaff() {
    std::ofstream out("D:\\Projects_C_C++\\tp-lab5\\tp-lab5\\stats.txt");
    out << getGroupsWithStudents().str();
    out << makeStatistics().str();
    out.close();
}

void Deanery::initHeads() {
    for (auto &group : *groups) {
        group->chooseHead();
    }
}

std::stringbuf Deanery::getHeads() {
    std::stringbuf str;
    std::ostream stream(&str);
    stream << "Heads of groups" << '\n';
    for (auto &group : *groups) {
        stream <<  group->title << '\n' << '\t' <<
            group->getHead()->getID() << ": " <<
            group->getHead()->getFIO() << '\n';
    }
    return str;
}

void Deanery::printHeads() {
    std::cout << getHeads().str();
}

std::vector<Group *>* Deanery::getGroups() const {
    return groups;
}
