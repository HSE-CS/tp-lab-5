// Copyright 2021 Kris

#include "Deanary.h"

void Deanary::createGroups(const std::string& filename) {
    std::ifstream groupFile(filename);
    std::string line;
    std::string line2;
    if (groupFile) {
        while (std::getline(groupFile, line)) {
            std::getline(groupFile, line2);
            AddGroup(line, line2);
        }
        groupFile.close();
    }
}

Group Deanary::getLastGroup() {
    return groups.back();
}

void Deanary::AddGroup(std::string titl, std::string spec) {
    Group newgroup = Group(titl, spec);
    this->groups.push_back(newgroup);
}

void Deanary::printGroups() {
    for (Group gr : groups) {
        std::cout << gr.gettitle() << std::endl;
    }
}

void Deanary::hireStudents(const std::string& filename) {
    std::ifstream groupFile(filename);
    std::string line;
    std::string line2;
    std::string line3;
    if (groupFile) {
        while (std::getline(groupFile, line)) {
            std::getline(groupFile, line2);
            std::getline(groupFile, line3);
            for (Group gr : groups) {
                if (line3 == gr.gettitle()) {
                    Student newst = Student(std::stoi(line), line2);
                    gr.addStudent(&newst);
                    newst.addToGroup(&gr);
                }
            }
        }
        groupFile.close();
    }
}

void Deanary::addMarksToAll() {
    std::srand(12);
    for (Group group : groups) {
        for (Student* student : group.getstudents()) {
            Student st = *student;
            for (int i = 0; i < 10; i++) {
                st.addmark(std::rand() % 10 + 1);
            }
        }
    }
}

std::vector<float> Deanary::getStatistics() {
    std::vector<float> statistic;
    for (Group gr : groups) {
        statistic.push_back(gr.getAveragemark());
    }
    return statistic;
}

void Deanary::moveStudents(Student* st1, Group* gr2) {
    Group gr = *gr2;
    gr.addStudent(st1);
    Student st = *st1;
    Group gr1 = *(st.getGroup());
    gr1.removeStudent(st1);
    st.addToGroup(gr2);
}

void Deanary::saveStaff(const std::string& fileName) {
    std::ofstream outFile;
    outFile.open(fileName);
    std::string data = "";
    if (outFile.is_open()) {
        for (Group gr : groups) {
            data = data + gr.gettitle() + " ";
            data = data + std::to_string(gr.getAveragemark());
            data = data +  + "\n";
        }
        outFile << data;
        outFile.close();
    }
}

void Deanary::initHeads() {
    for (Group gr : groups) {
        gr.chooseHead();
    }
}

void Deanary::fireStudents() {
    for (Group gr : groups) {
        for (Student* student : gr.getstudents()) {
            Student st = *student;
            if (st.getAveragemark() < 3.5) {
                gr.removeStudent(student);
            }
        }
    }
}
