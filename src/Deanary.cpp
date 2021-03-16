// Copyright 2021 Grachev Alexander

#include "../include/Deanary.h"

// void Deanary::addStudents(std::fstream& fileName) {
//
// }

void Deanary::addRandMarks() {
    for (int i = 0; i < groups.size(); i++) {
        for (int j = 0; j < groups[i].students.size(); j++) {
            for (int k = 0; k < 5; k++)
                groups[i].students[j].addMark(std::rand() % 10);
        }
    }
}

void Deanary::getStatistic() {
    for (auto groupIndex : groups) {
        std::cout << "Group " << groupIndex.getTitle()
        << " statistics: " << groupIndex.getMidMark() << std::endl;
        for (auto studentIndex : groupIndex.students) {
            std::cout << "Student " << studentIndex.getName()
            << " statistics: " << studentIndex.getMidMark() << std::endl;
        }
    }
}

void Deanary::moveStudent(Student student, Group newGroup) {
    student.group->removeStudent(student.getName());
    student.addGroup(newGroup);
}

void Deanary::expelStudents(std::fstream& fileName) {
    for (int i = 0; i < groups.size(); i++) {
        for (int j = 0; j < groups[i].students.size(); j++) {
            if (groups[i].students[j].getMidMark() < 3.5) {
                groups[i].removeStudent(groups[i].students[j].getName());
                std::string str;
                while (std::getline(fileName, str)) {
                    if (str.find(groups[i].students[j].getName())
                        != -1) str.clear();
                }
            }
        }
    }
}

// void Deanary::saveStaff() {
//
// }

void Deanary::initLeaders() {
    for (int i = 0; i < groups.size(); i++) {
        int randomHead = std::rand() % groups[i].students.size() + 1;
        groups[i].chooseLeader(groups[i].students[randomHead]);
    }
}

void Deanary::info() {
    for (int i = 0; i < groups.size(); i++) {
        std::cout << "Group: " << groups[i].getTitle() << std::endl;
        std::cout << "Leader: " << groups[i].head << std::endl;
        std::cout << "Students: " << std::endl;
        for (int j = 0; j < groups[i].students.size(); j++) {
            std::cout << groups[i].students[j].name << std::endl;
        }
    }
}
