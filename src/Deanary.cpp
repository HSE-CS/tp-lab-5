//
// Created by toliman on 03.02.2021.
//

#include <random>

#include "../include/Deanary.h"


std::vector<Student *> Deanary::createStudents(int count) {
    std::vector<Student *> students(count);
    std::ifstream input("../../Students/students-list.txt");
//    system("pwd");
    int amount;
    std::string name;
    input >> amount;
//    std::cout << amount << '\n';
    for (int i = 0; i < std::min(amount, count); ++i) {
        input >> name;
//        std::cout << name << std::endl;
        students[i] = new Student(i, name);
    }
    input.close();
    return students;
}

void Deanary::createGroup(const std::string &groupFile) {
    std::string groupTitle;
    int groupSize;
    std::ifstream input("../../Groups/" + groupFile);
    input >> groupSize;
    input >> groupTitle;
    auto group = new Group(groupTitle);
    group->setFileName(groupFile);
    std::string studentName;
    Student *student;
    std::getline(input, studentName);
    for (int i = 0; i < groupSize; ++i) {
        std::getline(input, studentName);
        std::random_device generator;
        student = new Student(generator(), studentName);
        group->addStudent(*student);
    }
    this->groups.push_back(group);
    input.close();
}

void Deanary::addMark(Student &student, int count) {
    std::random_device generator;
    std::mt19937 gen(generator());
    std::normal_distribution<float> nd(7, 3.5);
    for (int i = 0; i < count; ++i) {
        int mark = nd(generator);
        if (mark > 10)
            mark = 10;
        if (mark < 0)
            mark = 0;
        student.addMark(mark);
    }
}

void Deanary::getStats() {
    std::string stats("Some statistics:\n");
    for (auto group : this->groups) {
        for (auto s : group->getStudents()) {
            this->addMark(*s, 10);
        }
        stats += "=====\nGROUP ";
        stats += group->getTitle();
        stats += " - ";
        stats += std::to_string(group->getMiddleMark());
        stats += '\n';
        for (auto s : group->getStudents()) {
            stats += s->getFio() + " - " + std::to_string(s->getMiddleMark()) + '\n';
        }
    }
    stats += "=====";
    std::cout << stats << '\n';
}

std::vector<Group *> Deanary::getGroups() {
    return this->groups;
}

void Deanary::changeGroup(Student &student, Group &group) {
    student.getGroup()->deleteStudent(student);
    group.addStudent(student);
}

void Deanary::removeFoolStudents() {
    for (auto g : this->getGroups()) {
        for (auto s : g->getStudents()) {
            if (s->getMiddleMark() < 4) {
                g->deleteStudent(*s);
            }
        }
    }
}

void Deanary::save() {
    for (auto g : this->getGroups()) {
        std::cout << g->getTitle();
        std::ofstream output("../../Groups1/" + g->getFileName());
        output << std::to_string(g->getStudents().size()) + '\n';
        output << g->getTitle() + '\n';
        for (auto s : g->getStudents()) {
            output << s->getFio() + '\n';
        }
        output.close();
    }
}

void Deanary::initializeHeadChoose() {
    for (auto g : this->getGroups()) {
        if (g->getHead() == nullptr) {
            g->chooseHead();
        }
    }
}

