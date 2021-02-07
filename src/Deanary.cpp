// Copyright 2021 dmitrycvetkov2000

#include "Deanary.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <sstream>

std::vector<Group*>::const_iterator Deanary::findGroup(const std::string& name) {
    return std::find_if(std::begin(groups), std::end(groups), [&name](Group* const group) {
        return group->title == name;
        });
}

Deanary::~Deanary() {
    for (const auto& g : groups)
        delete g;
}

void Deanary::createGroups(std::ifstream& ifs) {
    std::string name;
    while (ifs >> name) {
        Group* group = new Group(name);
        groups.push_back(new Group(name));
    }
}

void Deanary::hireStudents(std::ifstream& ifs) {
    std::string line;
    while (std::getline(ifs, line)) {
        int id;
        std::stringstream ss(line);
        ss >> id;

        std::list<std::string> data;
        std::string chunk;
        while (ss >> chunk) {
            data.push_back(std::move(chunk));
        }
        const std::string groupName = data.back();
        data.pop_back();

        std::string name;
        for (const auto& el : data) {
            name += el;
            name += " ";
        }
        name.pop_back();

        Student* student = new Student(id, name);
        (*findGroup(groupName))->addStudent(student);

        int mark;
        while (ss >> mark) {
            student->addMark(mark);
        }
    }
}

void Deanary::addMarksToAll() {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(2, 5);
    auto makeRandomMark = [&rd, &dist]() -> int {
        return dist(rd);
    };

    std::for_each(std::begin(groups), std::end(groups), [&makeRandomMark](Group* const group) {
        std::for_each(std::begin(group->students), std::end(group->students), [&makeRandomMark](Student* const student) {
            student->addMark(makeRandomMark());
            });
        });
}

void Deanary::getStatistics() const {
    std::cout << "Всего групп: " << groups.size() << std::endl;
    std::cout << "Всего студентов: " << std::accumulate(std::begin(groups), std::end(groups), 0, [](auto a, const Group* const group) {
        return a + group->students.size();
        }) << std::endl;
    std::cout << "Информация по группам: " << std::endl;
    for (const auto& g : groups) {
        std::cout << g->title << std::endl;
        if (g->isEmpty()) {
            std::cout << "В группе нет студентов" << std::endl;
        }
        else {
            std::cout << "Староста: " << g->getStudent(g->headId)->name << std::endl;
            std::cout << "Средняя оценка: " << g->getAverageMark() << std::endl;

            auto worst = std::min_element(std::begin(g->students), std::end(g->students), [](const Student* const lhs, const Student* const rhs) {
                return lhs->getAverageMark() < rhs->getAverageMark();
                });
            std::cout << "Худший студент: " << (*worst)->name << ", средний балл: " << (*worst)->getAverageMark() << std::endl;

            auto best = std::max_element(std::begin(g->students), std::end(g->students), [](const Student* const lhs, const Student* const rhs) {
                return lhs->getAverageMark() < rhs->getAverageMark();
                });
            std::cout << "Лучший студент: " << (*best)->name << ", средний балл: " << (*best)->getAverageMark() << std::endl;
        }
    }
}

void Deanary::moveStudent(const std::string& groupName, const int studentId, const std::string& targetGroupName) {
    auto srcIter = findGroup(groupName);
    auto dstIter = findGroup(targetGroupName);
    Student* student = (*srcIter)->getStudent(studentId);
    (*srcIter)->removeStudent(studentId);
    (*dstIter)->addStudent(student);
}

void Deanary::saveStaff(std::ofstream& ofs) const {
    for (const auto& g : groups) {
        ofs << g->title << std::endl;
        if (g->isEmpty()) {
            ofs << "Нет студентов" << std::endl;
        }
        else {
            ofs << "Староста: " << g->getStudent(g->headId)->name << std::endl;
            ofs << "Средний балл: " << g->getAverageMark() << std::endl;
            ofs << "Студенты:" << std::endl;
            const auto students = g->students;
            for (const auto& student : students) {
                ofs << student->id << " " << student->name << " ";
                const auto marks = student->marks;
                if (!marks.empty()) {
                    for (const auto& mark : marks) {
                        ofs << mark << " ";
                    }
                    ofs << "(" << student->getAverageMark() << ")" << std::endl;
                }
                else {
                    ofs << std::endl;
                }
            }
        }
        ofs << std::endl;
    }
}

void Deanary::initHeads() {
    for (const auto& g : groups) {
        if (!g->isEmpty()) {
            g->chooseHead(g->students[0]->id);
        }
    }
}

void Deanary::fireStudent(const std::string& groupName, const int studentId) {
    auto group = findGroup(groupName);
    Student* student = (*group)->getStudent(studentId);
    (*group)->removeStudent(studentId);
    delete student;
}

