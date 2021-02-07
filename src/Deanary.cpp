// Copyright 06.02.21 DenisKabanov

#include "Deanary.h"
#include <stdlib.h>

Deanary::Deanary(std::string file) {
    groupid = 1;
    createGroups(file);
    initHeads();
}

void Deanary::createGroups(std::string fileninp) {
    std::ifstream file(fileninp);
    std::string input, spec, title;
    while (getline(file, input)) {
        int pos = input.find(':');
        spec = input.substr(0, pos);
        title = input.substr(pos + 1, input.size() - pos - 1);
        std::cout << spec << "\n";
        Group* group = new Group(title, spec);
        groups.push_back(group);
    }
    file.close();
}

void Deanary::hireStudents(std::string filename) {
    std::ifstream file(filename);
    std::string input;
    while (getline(file, input)) {
        Student* stud = new Student(groupid++, input);
        std::mt19937 gen(time(0));
        std::uniform_int_distribution<> uid(0, groups.size() - 1);
        int newstudid = uid(gen);
        groups[newstudid]->addStudent(stud);
        stud->addToGroup(groups[newstudid]);
    }
    file.close();
}

void Deanary::addMarksToAll() {
    for (auto group : groups) {
        for (auto stud : group->containsStudents()) {
            std::mt19937 gen(time(0));
            std::uniform_int_distribution<> uid(0, 5);
            int mark = uid(gen);
            stud->addMark(mark);
        }
    }
}

void Deanary::getStatistics(std::string filename) {
    std::ofstream filestat(filename);
    filestat.precision(2);
    filestat.setf(std::ios::fixed);
    for (auto group : groups) {
        filestat << group->getSpec() << "\n" << group->getTitle() << "\n";
        filestat << "Average mark: " << group->getAveragemark() << "\n";
        auto groupcont = group->containsStudents();
        for (auto stud : groupcont) {
            filestat << stud->getId() << " " << stud->getFio()
<< " " << stud->getAveragemark() << "\n";
        }
    }
}

void Deanary::moveStudents(int id, std::string title) {
    Student* stud = getStudent(id);
    Group* group = getGroup(title);
    stud->getGroup()->removeStudent(stud);
    group->addStudent(stud);
    stud->addToGroup(group);
}

void Deanary::saveStaff(std::string filegroups, std::string filestudents) {
    std::ofstream fgroups(filegroups);
    std::ofstream fstudents(filestudents);
    for (auto group : groups) {
        auto groupcont = group->containsStudents();
        fgroups << group->getSpec() << ":" << group->getTitle() << "\n";
        for (auto stud : groupcont) {
            fstudents << stud->getFio() << "\n";
        }
    }
    fgroups.close();
    fstudents.close();
}

void Deanary::initHeads() {
    for (auto g : groups) {
        g->chooseHead();
    }
}

void Deanary::fireStudents() {
    for (auto group : groups) {
        auto groupcont = group->containsStudents();
        for (auto stud : groupcont) {
            float mark = stud->getAveragemark();
            if (mark < 3.0) {
                group->removeStudent(stud);
            }
        }
    }
}

Group* Deanary::getGroup(std::string title) {
    int flag = 0;
    for (auto group : groups) {
        if (group->getTitle() == title) {
            flag = 1;
            return group;
        }
    }
    if (flag == 0)
        return nullptr;
}

Student* Deanary::getStudent(int id) {
    int flag = 0;
    Student* find = nullptr;
    for (auto group : groups) {
        find = group->getStudent(id);
        if (find != nullptr) {
            flag = 1;
            return find;
        }
    }
    if (flag == 0)
        return nullptr;
}
