// Copyright 2021 Tyulin Igor

#include <random>
#include "Deanary.h"

void Deanary::hireStudents(Student* stud, std::string ng) {
    for (int i = 0; i < groups.size(); i++) {
        if (groups[i]->getspec() == ng)
            groups[i]->addstud(stud);
    }
}

void Deanary::hireStudents(std::string path) {
    std::ifstream fin(path);
    int id = 1;
    std::string fio;
    while (getline(fin, fio)) {
        Student chel(id, fio);
        Students.push_back(chel);
        id++;
    }
}

void Deanary::addMarksToAll() {
    for (int i = 0; i < groups.size(); i++) {
        for (int j = 0; j < groups[i]->students.size(); j++) {
            for (int k = 0; k < 5; k++)
                groups[i]->students[j]->mark_add(std::rand() % 11);
        }
    }
}

void Deanary::createGroups(Group group) {
    std::string title = group.getitle();
    std::string spec = group.getspec();
    groups.push_back(new Group(title, spec));
}

void Deanary::createGroups(std::ifstream& groupsStream) {
    std::string title;
    std::string spec;
    while (!groupsStream.eof()) {
        std::getline(groupsStream, title, ' ');
        std::getline(groupsStream, spec, ' ');
        groups.push_back(new Group(title, spec));
    }
}

void Deanary::getStatistics() {
    for (auto n : groups) {
        std::cout << "Group " << n->getitle()
                  << " statistics: " << n->studavermarks() << std::endl;
        for (auto studin : n->students) {
            std::cout << "Student " << studin->stud_fio()
                      << " statistics: " << studin->average_mark() << std::endl;
        }
    }
}

void Deanary::initHeads() {
    for (int i = 0; i < groups.size(); i++) {
        int rnh = std::rand() % groups[i]->students.size() + 1;
        groups[i]->sethead(groups[i]->students[rnh]);
    }
}

void Deanary::saveStaff(std::string str) {
    std::ofstream file(str);
    for (auto & group : groups) {
        file << "Group title: " << group->getitle()
             << " Specialization: " << group->getspec() << '\n'
             << "Head: " << group->head->fio << '\n';
        for (Student *student : group->students) {
            file << student->id << ' ' << student->fio << ' ';
            for (int i = 0; i < student->marks.size(); i++) {
                file << student->marks[i];
            }
            file << '\n';
        }
        file << '\n';
    }
    file.close();
}

void Deanary::fireStudent(const std::vector<Student *> &students) {
    for (Student *student : students) {
        student->group->kickstud(student);
    }
}

void Deanary::moveStudents(Student* student, std::string groupName) {
    (student->group)->kickstud(student);
    hireStudents(student, groupName);
}
