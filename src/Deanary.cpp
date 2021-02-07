#include "Deanary.h"
#include <fstream>
#include <random>
#include <iostream>
#include "Student.h"


void Deanery::addRandomMarks() {
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<> distribution(0, 10);
    for (auto group : this->groups) {
        for (auto student : group->students) {
            for (int i = 0; i < 10; i++) {
                int mark = distribution(generator);
                student->addMark(mark);
            }
        }
    }
}

void Deanery::createStudents() {
    for (auto group: this->groups) {
        std::ifstream students(group->getTitle() + ".txt");
        while (!students.eof()) {
            int id = 0;
            char* fio = new char[70];
            students.getline(fio, 70, '\n');
            if (fio[0] == '\0') {
                continue;
            } else {
                group->addStudent(new Student(id++, std::string(fio)));
            }

        }
    }
}

void Deanery::createGroups() {
    std::ifstream fin("groups.txt");
    while (!fin.eof()) {
        std::string groupName;
        fin >> groupName;
        if (!groupName.empty()) {
            this->groups.push_back(new Group(groupName));
        } else {
            continue;
        }
    }
    fin.close();
}

void Deanery::getStat() {
    for (auto group : this->groups) {
        for (auto student : group->students) {
            std::cout << student->getName() << " " << student->getAverageMark() << std::endl;
        }
    }
}

void Deanery::moveStudent(Student *student, Group *destination) {
    student->group->removeStudent(student);
    destination->addStudent(student);
}

void Deanery::initHeadChoice() {
    for (auto group : this->groups) {
        group->chooseHead();
    }
}

void Deanery::fireStudents() {
    for (auto group : this->groups) {
        for (auto student : group->students) {
            if (student->getAverageMark() < 3.5) {
                student->group->removeStudent(student);
            }
        }
    }
}

void Deanery::saveNewData() {
    std::fstream fout("group.txt");
    for (auto group : this->groups) {
        fout << group->getTitle() << '\n';
    }
    for (auto group : this->groups) {
        std::fstream f_out(group->getTitle() + ".txt");
        for (auto student: group->students) {
            f_out << student->getName() << '\n';
        }
    }
}
