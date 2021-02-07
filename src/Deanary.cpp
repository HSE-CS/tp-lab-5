// Copyright 2021 Lab_5 TiNa
#include "Deanary.h"
#include <iostream>
#include <fstream>
#include <string>

void Deanery::hireStudents() {
    std::ifstream filein("students.txt");
    std::string fname;
    int newid = 1;
    std::vector<Student*> new_students;
    if (filein.is_open()) {
        while (!filein.eof()) {
            getline(filein, fname);
            new_students.push_back(new Student(newid++, fname));
        }
    }
    distribStud(new_students);
    filein.close();
}

void Deanery::distribStud(std::vector<Student*> new_students) {
    srand(time(NULL));
    int ind = 0;
    for (int i = 0; i < new_students.size(); i++) {
        ind = rand() % groups.size();
        groups[ind]->addStudent(new_students[i]);
    }
}

void Deanery::createGroups() {
    std::ifstream filein("groups.txt");
    std::string specf;
    std::string titlef;
    if (filein.is_open()) {
        while (!filein.eof()) {
            filein >> specf;
            filein >> titlef;
            groups.push_back(new Group(titlef, specf));
        }
    }
    filein.close();
}

void Deanery::addMarksToAll() {
    srand(time(NULL));
    for (int gri = 0; gri < groups.size(); gri++) {
        for (int sti = 0; sti < groups[gri]->students.size(); sti++) {
            for (int i = 0; i < 7; i++) {
                groups[gri]->students[sti]->addMark(rand() % 11);
            }
        }
    }
}

void Deanery::getStatistics() {
    for (int gri = 0; gri < groups.size(); gri++) {
        std::cout << groups[gri]->getTitle() << " " << groups[gri]->getSpec() << " ";
        std::cout << "Average mark - " << groups[gri]->getAveragemark_Gr() << std::endl;
        for (int sti = 0; sti < groups[gri]->students.size(); sti++) {
            std::cout << groups[gri]->students[sti]->getFio() << " ";
            std::cout << groups[gri]->students[sti]->getId() << " ";
            std::cout << "Average mark - " << groups[gri]->students[sti]->getAveragemark() << std::endl;
        }
        std::cout << std::endl;
    }
}

void Deanery::moveStudents(int id, std::string title_from, std::string title_to) {
    for (int gri = 0; gri < groups.size(); gri++) {
        if (groups[gri]->getTitle() == title_from) {
            for (int sti = 0; sti < groups[gri]->students.size(); sti++) {
                if (groups[gri]->students[sti]->getId() == id) {
                    for (int grj = 0; grj < groups.size(); grj++) {
                        if (groups[grj]->getTitle() == title_to) {
                            groups[grj]->addStudent(groups[gri]->students[sti]);
                        }
                    }
                    groups[gri]->delStudent(groups[gri]->students[sti]);
                }
            }
        }
    }
}

void Deanery::fireStudent() {
    for (int gri = 0; gri < groups.size(); gri++) {
        for (int sti = 0; sti < groups[gri]->students.size(); sti++) {
            if (groups[gri]->students[sti]->getAveragemark() < 3.5) {
                groups[gri]->delStudent(groups[gri]->students[sti]);
            }
        }
    }
}

void Deanery::saveStaff() {
    std::ofstream file_gr("groups.txt");
    std::ofstream file_st("students.txt");
    if ((file_gr.is_open()) && (file_st.is_open())) {
        for (int gri = 0; gri < groups.size(); gri++) {
            file_gr << groups[gri]->getSpec() << " " << groups[gri]->getTitle() << "\n";
            for (int sti = 0; sti < groups[gri]->students.size(); sti++) {
                file_st << groups[gri]->students[sti]->getFio() << "\n";
            }
        }
    }
    file_gr.close();
    file_st.close();
}

void Deanery::initHeads() {
    for (int gri = 0; gri < groups.size(); gri++) {
        groups[gri]->chooseHead();
    }
}