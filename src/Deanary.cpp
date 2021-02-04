// Copyright 2021 GN
#include <Deanary.h>
#include <string>
#include <iostream>
#include <fstream>
void Deanary::acceptStudents() {
    std::string s;
    std::ifstream file("students.txt");
    int id = 1;
    while (getline(file, s)) {
        Student st(id, s);
        allStudents.push_back(st);
        id++;
    }
}
void Deanary::createGroups() {
    std::string s;
    std::ifstream file("groups.txt");
    while (getline(file, s)) {
        std::string s2;
        getline(file, s2);
        Group gr(s, s2);
        groups.push_back(gr);
    }
}
void Deanary::studentRegistration() {
    srand(time(NULL));
    for (int i = 0; i < allStudents.size(); i++) {
        int index = std::rand() % groups.size() + 0;
        groups[index].addStudent(&allStudents[i]);
    }
}
void Deanary::addMarks() {
    srand(time(NULL));
    for (int gr_i = 0; gr_i < groups.size(); gr_i++) {
        for (int st_i = 0; st_i < groups[gr_i].students.size(); st_i++) {
            for (int i = 0; i < 10; i++) {
                groups[gr_i].students[st_i]->addMark(std::rand() % 10 + 1);
            }
        }
    }
}
double Deanary::getStatisticByStudents(std::string fio_) {
    for (int gr_i = 0; gr_i < groups.size(); gr_i++) {
        for (int st_i = 0; st_i < groups[gr_i].students.size(); st_i++) {
            if (groups[gr_i].students[st_i]->getName() == fio_) {
                return groups[gr_i].students[st_i]->avMark();
            }
        }
    }
}
double Deanary::getStatisticByGroups(std::string spc_) {
    for (int gr_i = 0; gr_i < groups.size(); gr_i++) {
        if (groups[gr_i].getSpec() == spc_) {
            return groups[gr_i].av_mark();
        }
    }
}
void Deanary::transferStudent(std::string fio_, std::string spc_) {
    for (int gr_i = 0; gr_i < groups.size(); gr_i++) {
        for (int st_i = 0; st_i < groups[gr_i].students.size(); st_i++) {
            if (groups[gr_i].students[st_i]->getName() \
                == fio_ && groups[gr_i].getSpec() != spc_) {
                for (int gr_i1 = 0; gr_i1 < groups.size(); gr_i1++) {
                    if (groups[gr_i1].getSpec() == spc_) {
                        groups[gr_i1].addStudent(groups[gr_i].students[st_i]);
                    }
                }
                groups[gr_i].delStudent(groups[gr_i].students[st_i]);
            }
        }
    }
}
void Deanary::printAllInfo() {
    for (int gr_i = 0; gr_i < groups.size(); gr_i++) {
        std::cout << groups[gr_i].getName() << std::endl;
        std::cout << "Head of group is " \
            << groups[gr_i].getHead().getName() << std::endl;
        for (int st_i = 0; st_i < groups[gr_i].students.size(); st_i++) {
            std::cout << groups[gr_i].students[st_i]->getName() << std::endl;
        }
    }
}
void Deanary::initOfHeadElection() {
    for (int gr_i = 0; gr_i < groups.size(); gr_i++) {
        groups[gr_i].initHead();
    }
}
void Deanary::addStudent(Student* student, std::string spec_) {
    for (int gr_i = 0; gr_i < groups.size(); gr_i++) {
        if (groups[gr_i].getSpec() == spec_) {
            groups[gr_i].addStudent(student);
        }
    }
}
void Deanary::hireStudent(std::string fio_) {
    for (int gr_i = 0; gr_i < groups.size(); gr_i++) {
        for (int st_i = 0; st_i < groups[gr_i].students.size(); st_i++) {
            if (groups[gr_i].students[st_i]->getName() == fio_) {
                groups[gr_i].delStudent(groups[gr_i].students[st_i]);
            }
        }
    }
}
void Deanary::saveToFiles() {
    std::ofstream fout;
    fout.open("output.txt");
    for (int gr_i = 0; gr_i < groups.size(); gr_i++) {
        fout << "----------New group----------" << std::endl;
        fout << groups[gr_i].getName() << std::endl;
        fout << "Head of group is " << \
            groups[gr_i].getHead().getName() << std::endl;
        for (int st_i = 0; st_i < groups[gr_i].students.size(); st_i++) {
            fout << st_i+1 << ") " << \
                groups[gr_i].students[st_i]->getName() << std::endl;
        }
    }
    fout.close();
}
void Deanary::addGroup(Group gr_) {
    groups.push_back(gr_);
}
