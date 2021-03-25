// Copyright 2021 by Maxim

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <fstream>
#include <vector>
#include <string>
#include "Group.h"

class Deanery {
 private:
    vector<Group *> groups;
    int global_id;

 public:
    Deanery() {
        global_id = 0;
    }

    void hireStudents(std::string file_dir) {
        std::ifstream file(file_dir);
        std::string str;
        while (getline(file, str)) {
            int idx = std::rand() % groups.size();
            Student *student = new Student(global_id++, str);
            groups[idx]->addStudent(student);
            student->addToGroup(groups[idx]);
        }
        file.close();
    }

    void createGroups(std::string file_dir) {
        std::ifstream file(file_dir);
        std::string str;
        while (getline(file, str)) {
            int pos = str.find(' ');
            std::string spec = str.substr(0, pos);
            std::string title = str.substr(pos + 1, str.size() - pos - 1);
            groups.push_back(new Group(title, spec));
        }
        file.close();
    }

    void addMarksToAll() {
        for (int i = 0; i < groups.size(); i++) {
            auto students_ = groups[i]->getAllStudents();
            for (int j = 0; j < students_.size(); j++) {
                students_[j]->addmark(std::rand() % 5 + 1);
            }
        }
    }

    void getStatistics(std::string file_name) {
        std::ofstream file(file_name);
        file.setf(std::ios::fixed);
        file.precision(2);
        for (auto group : groups) {
            file << group->getSpec() << std::endl;
            file << group->getTitle() << std::endl;
            file << group->getAveragemark() << std::endl;
            auto students = group->getAllStudents();
            for (auto student : students) {
                file << "   " << student->getID() << " ";
                file << student->getFIO() << " ";
                file << student->getAveragemark() << std::endl;
            }
        }
    }

    void printData() {
        std::cout << std::fixed;
        std::cout.precision(2);
        for (auto group : groups) {
            std::cout << group->getSpec() << std::endl;
            std::cout << group->getTitle() << std::endl;
            std::cout << group->getAveragemark() << std::endl;
            auto students = group->getAllStudents();
            for (auto student : students) {
                std::cout << "   " << student->getID() << " ";
                std::cout << student->getFIO() << " ";
                std::cout << student->getAveragemark() << std::endl;
            }
        }
    }

    void saveStaff(std::string file_g, std::string file_s) {
        std::ofstream groups_file(file_g);
        std::ofstream student_file(file_s);
        for (auto group : groups) {
            auto students = group->getAllStudents();
            groups_file << group->getSpec() << " ";
            groups_file << group->getTitle() << std::endl;
            for (auto student : students) {
                student_file << student->getFIO() << " ";
            }
            student_file << std::endl;
        }
        student_file.close();
        groups_file.close();
    }

    void initHeads() {
        for (int i = 0; i < this->groups.size(); i++) {
            auto size = this->groups[i]->getAllStudents().size();
            this->groups[i]->chooseHead(std::rand() % size);
        }
    }

    void fireStudents() {
        for (auto group : groups) {
            auto students = group->getAllStudents();
            for (auto student : students) {
                float avg_mark = student->getAveragemark();
                if (avg_mark < 2.5) {
                    group->removeStudent(student);
                }
            }
        }
    }

    Group *getGroup(std::string title) {
        for (auto group : groups) {
            if (group->getTitle() == title) {
                return group;
            }
        }
        return nullptr;
    }

    Student *getStudent(int id) {
        for (auto g : groups) {
            if (g->getStudent(id) != nullptr)
                return g->getStudent(id);
        }
        return nullptr;
    }
};

#endif  // INCLUDE_DEANARY_H_
