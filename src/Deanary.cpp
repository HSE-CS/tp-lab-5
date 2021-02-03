// Copyright 2021 BekusovMikhail

#include "Deanary.h"
#include <fstream>
#include <iostream>

std::vector<Group *> Deanary::getGroups() {
    return groups;
}

void Deanary::createGroups() {
    std::string ln;
    std::ifstream input(R"(C:\Users\Dns\CLionProjects\dekanat\groups.txt)");
    if (input.is_open()) {
        while (getline(input, ln)) {
            std::string t, s;
            int i = 0;
            while (ln[i] != ':') {
                t.push_back(ln[i]);
                i++;
            }
            i++;
            while (ln[i] != ';') {
                s.push_back(ln[i]);
                i++;
            }
            groups.push_back(new Group(t, s));
        }
    }
    input.close();
}

std::vector<Student *> Deanary::hireStudents() {
    std::string ln;
    std::ifstream input(R"(C:\Users\Dns\CLionProjects\dekanat\students.txt)");
    std::vector<Student *> students;
    if (input.is_open()) {
        while (getline(input, ln)) {
            std::string id, n;
            int i = 0;
            while (ln[i] != ':') {
                id.push_back(ln[i]);
                i++;
            }
            i++;
            while (ln[i] != ';') {
                n.push_back(ln[i]);
                i++;
            }
            students.push_back(new Student(id, n));
        }
    }
    input.close();
    return students;
}

void Deanary::addMarksToAll() {
    unsigned int rrr = 1;
    for (Group *g : this->getGroups()) {
        for (Student *st : g->getStudents()) {
            st->addMark(rand_r(&rrr) % 10 + 1);
        }
    }
}

void Deanary::getStatistics() {
    for (Group *gr : this->getGroups()) {
        std::cout << gr->getTitle() << ", " << gr->getSpec() << std::endl;
        std::cout << "Head: " << gr->getHead()->getFIO() << std::endl;
        std::cout << "AvMarkOfGroup: " << gr->getAverageMark() << std::endl;
        for (Student *stud : gr->getStudents()) {
            std::cout << "Name: " << stud->getFIO() <<
            ", ID:" << stud->getId() << ", ";
            std::cout << "AvMark: " << stud->getAverageMark() << std::endl;
        }
        std::cout << std::endl;
    }
}

void Deanary::moveStudents(Group *f, Group *t, std::vector<Student *> stds) {
    for (Student *st : stds) {
        f->removeStudent(st);
        t->addStudent(st);
    }
}

void Deanary::saveStaff() {
    std::ofstream output;
    output.open(R"(C:\Users\Dns\CLionProjects\dekanat\Stat.txt)");
    if (output.is_open()) {
        for (Group *gr : this->getGroups()) {
            output << gr->getTitle() << ", " << gr->getSpec() << std::endl;
            output << "Head: " << gr->getHead()->getFIO() << std::endl;
            output << "AvMarkOfGroup: " << gr->getAverageMark() << std::endl;
            for (Student *stud : gr->getStudents()) {
                output << "Name: " << stud->getFIO() <<
                ", ID:" << stud->getId() << ", ";
                output << "AvMark: " << stud->getAverageMark() << std::endl;
            }
            output << std::endl;
        }
    }
}

void Deanary::initHeads() {
    unsigned int rrr = 1;
    for (Group *g : this->getGroups()) {
        g->chooseHead(g->getStudents()[rand_r(&rrr) % g->getStudents().size()]);
    }
}

void Deanary::fireStudents(std::vector<Student *> stds) {
    for (Group *g : this->getGroups()) {
        for (Student *st : stds) {
            if (g->containsStudent(st)) {
                g->removeStudent(st);
            }
        }
    }
}

void Deanary::sortStudents(std::vector<Student *> stds) {
    int i = 0;
    for (Student *st : stds) {
        this->getGroups()[i % this->getGroups().size()]->addStudent(st);
        i++;
    }
}
