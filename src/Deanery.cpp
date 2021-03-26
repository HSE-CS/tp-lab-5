// Copyright [2021] <Nikita Semaev>
#include <initializer_list>
#include <string>
#include <fstream>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "../include/Deanery.h"
#include "../include/Student.h"

Deanery::Deanery(std::initializer_list <std::string> filesList) {
    this->groups.reserve(filesList.size());
    for (std::size_t i = 0; i < filesList.size(); ++i) {
        this->groups.push_back(new Group("Group" + std::to_string(i)));
        std::ifstream myfile(*(filesList.begin() + i));
        std::string line;
        if (myfile.is_open()) {
            uint16_t id = 0;
            while (std::getline(myfile, line)) {
                Student *student = new Student(id, std::move(line));
                this->groups[i]->addStudent(student);
            }
            myfile.close();
        }
    }
}

void Deanery::randomMarks() {
    for (auto group : this->groups) {
        for (auto student : group->getStudents()) {
            student->addMark(std::rand() % 4 + 2);
        }
    }
}

const std::vector <Group *> &Deanery::getGroups() const {
    return this->groups;
}

std::ostream& operator<<(std::ostream& os, Deanery &deanery) {
    for (auto group : deanery.getGroups()) {
        os << "Group: " << group->getTitle() << std::endl;
        for (auto student : group->getStudents()) {
            os << " - " << student->fio << " : ";
            os << student->averageMark() << std::endl;
        }
    }
    return os;
}
