// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 06.02.2021.
//
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "Deanary.h"
#include "Group.h"
#include "Student.h"


Group *Deanary::createGroup(std::string valSpec, int valTitle) {
    return groups.emplace_back(new Group(std::move(valSpec), valTitle));
}

void Deanary::addMarks() {
    for (auto gr : groups) {
        for (auto st : gr->students) {
            st->addMark((int) std::rand() % 10);
        }
    }
}

Student *Deanary::hireStudent(unsigned int id, std::string fio,
                              std::string spec, int title) {
    auto g = findGroup(title);
    if (g == nullptr) {
        g = createGroup(std::move(spec), title);
    }
    return g->createStudent(id, std::move(fio));
}

std::string Deanary::getStat() const {
    std::string stat;
    for (auto gr : groups) {
        stat += "Group: "
                + std::to_string(gr->title)
                + " Spec: "
                + gr->spec
                + " Size "
                + std::to_string(gr->students.size())
                + "\nStudents:\n";
        for (auto st : gr->students) {
            stat += std::to_string(st->id)
                    + " "
                    + st->fio
                    + '\n';
        }
        stat += "\n\n";
    }
    return stat;
}

void Deanary::transferStudent(unsigned int id, int title) {
    auto gr = findGroup(title);
    auto st = findStudent(id);
    if (st != nullptr && gr != nullptr) {
        st->group->removeStudent(st);
        gr->addStudent(st);
    }
}

void Deanary::saveStaff(const std::string &filename) const {
    std::ofstream f(filename);
    f << getStat();
    f.close();
}

void Deanary::initHeads() {
    for (auto g : groups)
        g->chooseHead();
}

Group *Deanary::findGroup(int title) {
    for (auto g : groups) {
        if (g->title == title) {
            return g;
        }
    }
    return nullptr;
}

Student *Deanary::findStudent(unsigned int id) {
    for (auto g : groups) {
        for (auto s : g->students) {
            if (s->id == id) {
                return s;
            }
        }
    }
    return nullptr;
}

void Deanary::readFile(const std::string &filename) {
    std::ifstream f(filename);
    if (!f.is_open()) {
        std::cout << "GG";
        return;
    }
    std::string res, trash;
    f >> res;
    std::cout << res;
    while (res == "Group:") {
        if (res == "Group:") {
            f >> res;
            int title = std::stoi(res);
            f >> res;
            f >> res;
            std::string spec = res;
            auto group = createGroup(spec, title);
            f >> res;
            f >> res;
            int numberOfStudents = std::stoi(res);
            int count = 0;
            f >> res;
            while (count < numberOfStudents) {
                f >> res;
                unsigned int id = std::stoi(res);
                count++;
                std::string fio;
                f >> res;
                fio += res + ' ';
                f >> res;
                fio += res + ' ';
                f >> res;
                fio += res + ' ';
                hireStudent(id, fio, spec, title);
            }
            f >> res;
        }
    }
    f.close();
}
