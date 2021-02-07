// Copyright 2021 Stifeev Nikita

#include "Deanary.h"

Deanary::Deanary() {
    std::ofstream ofs("deanary.txt");
    ofs.close();
}

void Deanary::createGroups(std::string fileName) {
    std::ifstream file;
    file.open(fileName);
    if (file) {
        std::string s;
        while (!file.eof()) {
            getline(file, s);
            Group* grp =
                new Group(s.substr(0, s.find(' ')),
                    s.substr(s.find(' ') + 1, s.length()));
            groups.push_back(grp);
        }
    }
    file.close();
}

std::vector<Group*> Deanary::getGroups() const {
    return this->groups;
}

void Deanary::createStudents(std::string fileName) {
    std::ifstream file;
    file.open(fileName);
    if (file) {
        std::string s;
        int id = 0;
        while (!file.eof()) {
            getline(file, s);
            Student* stp = new Student(id, s);
            stp->addToGroup(groups[id % 5]);
            groups[id % groups.size()]->addStudent(stp);
            id++;
        }
    }
    file.close();
}

void Deanary::addMarksToAll() {
    for (int i = 0; i < groups.size(); i++) {
        std::vector<Student*> sds = groups[i]->getStudent();
        for (int j = 0; j < sds.size(); j++) {
            sds[j]->addmark(std::rand() % 5 + 1);
            std::cout << sds[j]->getID() << " ";
            std::cout << sds[j]->getFIO() << " ";
            std::cout << sds[j]->calcAv() << "\n";
        }
    }
}

std::vector<double> Deanary::getStatistics() {
    std::vector<double> res;
    for (int i = 0; i < groups.size(); i++) {
        res.push_back(groups[i]->calcMean());
    }
    return res;
}

void Deanary::moveStudents(Student* st, Group* gr1, Group* gr2) {
    gr1->exclude(st->getID());
    st->addToGroup(gr2);
    gr2->addStudent(st);
}

void Deanary::fireStudents() {
    for (int i = 0; i < groups.size(); i++) {
        groups[i]->excludeBadStudents();
    }
}

void Deanary::save(std::string filename) {
    std::ofstream out;
    out.open(filename);
    if (out.is_open()) {
        for (int i = 0; i < groups.size(); i++) {
            out << "Group: " << groups[i]->getTitle() << std::endl;
            for (int j = 0; j < groups[i]->getStudent().size(); j++) {
                out << "ID: " << groups[i]->getStudent()[j]->getID()
                    << std::endl;
                out << "Stud: " << groups[i]->getStudent()[j]->getFIO()
                    << std::endl;
                out << "Mark: " << groups[i]->getStudent()[j]->calcAv()
                    << std::endl;
                out << "\n";
            }
        }
    }
}

Deanary::~Deanary() {
}
