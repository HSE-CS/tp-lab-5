// Copyright 2021 MalininDmitry
#include <random>
#include <iostream>
#include "Group.h"
#include "Student.h"
#include "Deanary.h"



void Deanary::createGroups(std::string filename) {
    std::string input;
    std::string spec;
    std::string title;
    std::ifstream file(filename);
    int i = 0;
    while (getline(file, input)) {
        int pos = input.find(':');
        spec = input.substr(0, pos);
        title = input.substr(pos + 1, input.size() - pos - 1);
        Group* g = new Group(title, spec);
        i++;
        groups.push_back(g);
    }
    file.close();
}

void Deanary::initHeads() {
    for (auto g : groups) {
        g->chooseHead();
    }
}

Deanary::Deanary(std::string filename) {
    createGroups(filename);
    initHeads();
}

void Deanary::hireStudents(std::string filename) {
    std::string input;
    std::ifstream file(filename);
    int index = 0;
    unsigned int seed = 5;
    srand(0);
    while (getline(file, input)) {
        Student* stud = new Student(0, input);
        index = rand_r(&seed) % (this->groups.size());
        stud->changeId(this->groups[index]->countStudent());
        this->groups[index]->addStudent(stud);
    }

    file.close();
}

void Deanary::addMarksToAll(int mark) {
    for (int i = 0; i < groups.size(); i++) {
        for (int j = 0; j < groups[i]->countStudent(); j++) {
            groups[i]->listStudent()[j]->addMark(mark);
        }
    }
}

void Deanary::getStatistics(std::string filename) {
    std::ofstream out;
    out.open(filename);
    out << "Groups :" << std::endl;

    for (int i = 0; i < this->groups.size(); i++) {
        out << this->groups[i]->getTitle()
        << " : " << this->groups[i]->getAverageMark()
        << std::endl;
    }
    out << "Students :" << std::endl;

    for (int i = 0; i < this->groups.size(); i++) {
        for (int j = 0;
             j < this->groups[i]->listStudent().size();
             j++) {
            out <<
            this->groups[i]->listStudent()[j]->getFio()
            << " : " <<
            this->groups[i]->listStudent()[j]->getAveragemark()
            << std::endl;
        }
    }

    out.close();
}

void Deanary::moveStudents(Student * student, Group * group) {
    student->getGroup()->removeStudent(student);
    group->addStudent(student);
}

void Deanary::fireStudents() {
    for (Group* g : this->groups) {
        std::vector<Student*> gg = g->listStudent();
        for (Student* s : gg) {
            if (s->getAveragemark() < 3.5)
                g->removeStudent(s);
        }
    }
}

void Deanary::saveStaff(std::string filename_group,
    std::string filename_students) {
    std::ofstream fgroup(filename_group);
    std::ofstream fstudent(filename_students);

    for (auto g : this->groups) {
        fgroup << g->getTitle() << ":"
        << g->getSpec() << std::endl;
        auto gg = g->listStudent();
        for (auto s : gg) {
            fstudent << s->getFio()
            << std::endl;
        }
    }

    fgroup.close();
    fstudent.close();
}

void Deanary::outputToConsole() {
    for (auto g : this->groups) {
        std::cout << g->getTitle() << " : "
        << g->getSpec() << " - "
        << g->getAverageMark() << std::endl;
        auto gg = g->listStudent();
        for (auto s : gg) {
            std::cout << s->getFio() << " - " <<
            s->getAveragemark()
            << std::endl;
        }
    }
}
