// Copyright 2021 Bekina Svetlana
#include "Deanary.h"

Deanary::Deanary() {}
Deanary::~Deanary() {
	groups.clear();
}
void Deanary::createGroup() {
    std::string title;
    std::string spec;
    std::ifstream in("groups.txt");
    if (in.is_open()) {
        while (in >> title >> spec) {
            Group* group = new Group(title, spec);
            groups.push_back(group);
        }
    }
    in.close();
}

void Deanary::hireStudents() {
    std::string line;
    std::ifstream in("students.txt"); 
    if (in.is_open()) {	
        size_t index = 0;
        while (getline(in, line)) {	
            for (size_t i = 0; i < groups.size(); i++) {
                if (groups[i]->getTitle() == line) {
                    index = i;
                    getline(in, line);
                    break;
                }
            }
            std::string size = std::to_string(groups[index]->getStudents().size() + 1);
            size_t n = size.size();
            for (int i = 0; i < 5 - n; i++) {
                size = '0' + size;
            }
            Student* student = new Student(groups[index]->getTitle() + '_' + size, line, groups[index]);
            groups[index]->addStudent(student);
        }
    }
    in.close();
}

void Deanary::addMarksToAll() {
    size_t n;
    srand(time(0));
    for (auto group : groups) {
        for (auto& student : group->getStudents()) {
            size_t n = 5 + rand() % 16;
            for (int i = 0; i < n; i++) {
                student->addmark(rand() % 11);
            }
        }
    }
}

void Deanary::getStatistics() const {
    std::cout << "Статистика\n";
    for (auto group : groups) {
        std::cout << "\nСредняя оценка группы " << group->getTitle() << '\t' << group->getAveragemark() << std::endl;
        std::cout << "\nСредние оценки студентов\n";
        for (auto student : group->getStudents()) {
            std::cout << student->getFio() << '\t' << student->getAveragemark() << std::endl;
        }
    }
}

void Deanary::moveStudents(std::string id, std::string title) {
    Student* st = nullptr;
    for (auto group : groups) {
        for (auto student : group->getStudents()) {
            if (student->getId() == id) {
                group->removeStudent(id);
                st = student;
                break;
            }
        }
        if (group->getTitle() == title) {
            group->addStudent(st);
        }
    }
}

void Deanary::saveStaff() {
    std::ofstream out;
    out.open("students.txt");
    if (out.is_open()) {
        for (auto group : groups) {
            out << group->getTitle() << std::endl;
            for (auto student : group->getStudents()) {
                out << student->getFio() << std::endl;
            }
        }
    }
    out.close();
}

void Deanary::fireStudents() {
    for (auto group : groups) {
        for (auto student : group->getStudents()) {
            if (student->getAveragemark() < 4) {
                group->removeStudent(student->getId());
            }
        }
    }
}

void Deanary::initHeads() {
    for (auto group : groups) {
        group->chooseHead();
    }
}

std::vector<Group*> Deanary::getgroups() const {
    return groups;
}
