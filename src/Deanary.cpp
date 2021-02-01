// Copyright 2020 Dmitry Vargin

#include <iostream>
#include <fstream>
// #include <filesystem>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <map>

#include "Deanary.h"

Deanery::Deanery() {}

void Deanery::hireStudents(std::string filename) {
    setlocale(LC_ALL, "rus");
    // std::string path = Deanery::getProjectPath() + "/data/" + filename;
    std::string path = "../../data/" + filename;
    std::ifstream input_file(path);
    if (!input_file.is_open()) {
        std::cout << filename << " did not open!\n";
        throw;
    }
    while (!input_file.eof()) {
        std::string line;
        getline(input_file, line);
        int id = std::stoi(line.substr(0, line.find(' ')));
        std::string name = line.substr(line.find(' ')+1,
                                       line.length());
        name = name.substr(0, name.find(' '));
        std::string group_name = line.substr(line.rfind(' ')+1,
                                             line.size());
        Group *his_group = nullptr;
        for (Group *group: this->groups) {
            if (!strcmp(group->getTitle().c_str(), group_name.c_str())) {
                his_group = group;
                break;
            }
        }
        if (his_group == nullptr) {
            his_group = new Group(group_name);
            this->groups.push_back(his_group);
        }
        Student *student = new Student(id, name, his_group);
        his_group->addStudent(student);
    }
}

void Deanery::createGroups(std::string filename) {
    setlocale(LC_ALL, "rus");
    // std::string path = Deanery::getProjectPath() + "/data/" + filename;
    std::string path = "../../data/" + filename;
    std::ifstream input_file(path);
    if (!input_file.is_open()) {
        std::cout << filename + " did not open!\n";
        throw;
    }
    while (!input_file.eof()) {
        std::string line;
        getline(input_file, line);
        Group *group = new Group(line);
        this->groups.push_back(group);
    }
    input_file.close();
}

void Deanery::addMarksToAll(int marks_per_student) {
    std::srand(std::time(nullptr));
    for (Group *group: this->groups) {
        for (Student *student: group->getStudents()) {
            for (int i = 0; i < marks_per_student; ++i) {
                student->addMark(std::rand() % 10 + 1);
            }
        }
    }
}

void Deanery::moveStudents(Student *student, Group *group) {
    student->getGroup()->removeStudents(student);
    group->addStudent(student);
}

Student *Deanery::fireStudents(Student *student) {
    for (Group *group: this->groups) {
        for (Student *student1: group->getStudents()) {
            if (student == student1) {
                group->removeStudents(student);
            }
        }
    }
    return student;
}

void Deanery::initHeads() {
    std::srand(std::time(nullptr));
    for (Group *group: this->groups) {
        int head_index = std::rand() % group->getStudents().size();
        group->chooseHead(group->getStudents()[head_index]);
    }
}

std::map<Group *, double> Deanery::getStatistics() {
    std::map<Group *, double> m;
    for (Group *group: this->getGroups()) {
        m[group] = group->getAveragemark();
    }
    return m;
}

void Deanery::saveStaff() {
//    std::string spath = getProjectPath() + "/data/studOutput.txt";
//    std::string gpath = getProjectPath() + "/data/groupOutput.txt";
    std::string spath = "../../data/studOutput.txt";
    std::string gpath = "../../data/groupOutput.txt";
    std::ofstream student_file(spath);
    std::ofstream group_file(gpath);

    for (Group *group: this->groups) {
        group_file << group->getTitle() << "\n";
    }
    group_file.close();
    for (Group *group: this->groups) {
        for (Student *student: group->getStudents()) {
            student_file << std::to_string(student->getId()) << " ";
            student_file << student->getFio() << " ";
            student_file << student->getGroup()->getTitle() << "\n";
        }
    }

    student_file.close();
}

std::vector<Group*> Deanery::getGroups() {
    return this->groups;
}

void Deanery::addGroup(Group *group) {
    this->groups.push_back(group);
}

std::string Deanery::getProjectPath() {
    /*
    std::string path = std::filesystem::current_path().string();
    path = path.substr(0, path.rfind('/'));
    return path.substr(0, path.rfind('/'));
     */
    return "";
}
