// Copyright 2020 Osmanov Islam
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Reader.h"
#include "Student.h"
#include "Group.h"
#include "Deanary.h"


Deanary::Deanary() {
    this->number_of_groups = 0;
}

void Deanary::createGroups(std::string StudentsFile, std::string GroupsFile) {
    Reader read;
    read.StudentsReader(StudentsFile);
    read.GroupsReader(GroupsFile);
    this->number_of_groups = read.groups.size();
    std::cout << this->number_of_groups << std::endl;
    for (int i = 0; i < this->number_of_groups; i++) {
        this->groups.push_back(this->hireStudents(StudentsFile,
                               new Group(read.groups[i].second,
                               read.groups[i].first),
                               std::to_string(i + 1)));
    }
}

void Deanary::addMarksToAll() {
    for (int i = 0; i < this->number_of_groups; i++) {
        for (int j = 0; j < this->groups[i]->students.size(); j++) {
            for (int k = 0; k < number_of_marks; k++) {
                int t = 1 + std::rand() % 10;
                this->groups[i]->students[j]->addMark(t);
            }
        }
    }
}

void Deanary::initHeads() {
    for (int i = 0; i < this->number_of_groups; i++) {
        int stud = 0 + std::rand() % this->groups[i]->students.size();
        this->groups[i]->chooseHead(this->groups[i]->students.at(stud));
    }
}

Group* Deanary::hireStudents(std::string StudentFile, Group *someGroup,
                             std::string groupId) {
    Reader Students;
    Students.StudentsReader(StudentFile);
    for (int j = 0; j < Students.names.size(); j++) {
        if (Students.names[j].first[0] == Students.ids[j].second[0]
           && Students.names[j].first[0] == groupId[0]) {
        someGroup->addStudent(new Student(
        atoi(Students.ids[j].second.c_str()),
        Students.names[j].second));
        }
    }
    return someGroup;
}

void Deanary::fireStudents() {
    for (int i = 0; i < this->number_of_groups; i++) {
        for (int j = 0; j < this->groups[i]->students.size(); j++) {
        double stud_aver = this->groups[i]->students.at(j)->getAveragemark();
            if (stud_aver < 3.5) {
                if (this->groups[i]->students.at(j)->isHeadOfGroup()) {
                int stud = 0 + std::rand() % this->groups[i]->students.size();
                groups[i]->removeStudent(this->groups[i]->students.at(j));
                this->groups[i]->chooseHead(this->groups[i]->students.at(stud));
                } else {
               groups[i]->students.erase(this->groups[i]->students.begin() + j);
                }
            }
        }
    }
}

void Deanary::moveStudent(Student *student, Group *other_group) {
    for (auto group : groups) {
        if (group == &other_group) {
            if (!group->containsStudent(student.getId())) {
                group->addStudent(&student);
            }
            return;
        }
    }
    for (auto group : groups) {
        if (group == student.group) {
            for (int i = 0; group->students.size(); i++) {
                if (group->students[i] == &student) {
                    group->students.erase(group->students.begin() + i);
                }
            }
        }
    }
}

void Deanary::getStatistics() {
    std::cout << "Mark statistics:" << std::endl;
    for (auto group : groups) {
        for (auto student : group->students) {
            std::cout << student->fio <<" has average mark: "
            << student->getAveragemark() << std::endl;
        }
    }

    for (auto group : groups) {
        std::cout << group->title << " has average mark: "
        << group->getAverageMark() << std::endl;
    }
}

void Deanary::printGroupsHeads() {
    for (int i = 0; i < this->number_of_groups; i++) {
        this->groups[i]->printHead();
    }
}

void Deanary::saveStuff(std::string filePath) {
    std::ofstream DeanFile(filePath);
    if (DeanFile.is_open()) {
        for (auto group : groups) {
            DeanFile << group->title<< "\n";
            for (auto student : group->students) {
                std::string marks = " ";
                for (auto mark : student->marks) {
                    marks = marks + std::to_string(mark) + " ";
                }
                DeanFile << std::to_string(student->getId()) << ":"
                << student->getFIO() << " -" << marks << "\n";
            }
        }
    }
    DeanFile.close();
}

Group Deanary::getGroup(int ind) {
    return *this->groups[ind];
}

int Deanary::getNumGroups() {
    return this->number_of_groups;
}
