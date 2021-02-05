// Copyright 2021 Igumnova Natasha
#include "Deanary.h"
#include "Data.h"
#include <fstream>
#include <string>
#include <cmath>
Deanary::Deanary() {
    this->groups = nullptr;
    this->count = 0;
}
Deanary::Deanary(int count_, std::string filename) {
    this->groups = new Group[count_];
    this->count = count_;
    createGroups(this->hireStudents(filename), filename);
}

std::vector<Student*> Deanary::hireStudents(std::string filename) {
    std::vector<std::string> data = read_data(filename);
    int k = 0;
    std::vector<std::string> gr;
    std::vector<Student*> res;
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == "***") {
            Group g = *new Group(gr[0], gr[1]);
            this->groups[k] = g;
            for (int j = 2; j < gr.size(); j++) {
                std::vector<int> mark = getmarks(gr[j]);
                int id_ = getid(gr[j]);
                std::string name = getfio(gr[j]);
                Student* st = new Student(id_, name, nullptr, mark);
                res.push_back(st);
            }
            k += 1;
            gr.clear();
        } else {
            gr.push_back(data[i]);
        }
    }
    return res;
}

void Deanary::createGroups(std::vector<Student*>st, std::string file) {
    std::vector<std::string> data = read_data(file);
    int k = 0, start = 0, num = st.size()/count;
    std::vector<std::string> gr;
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == "***") {
            for (int j = start; j < start+num; j++) {
                groups[k].addStudent(st[j]);
            }
            start+=num;
            k += 1;
        }
    }
    initHeads();
}
Group* Deanary::findGroupTitle(std::string gr) {
    for (int i = 0;i < this->count;i++) {
        if (groups[i].getTitle() == gr) {
            return (&groups[i]);
        }
    }
    return nullptr;
}
void Deanary::addMarksToAll(std::string gr) {
    int mark;
    Group* group = findGroupTitle(gr);
    if (group != nullptr) {
        for (int i = 0;i < group->students.size();i++) {
            std::cout << group->students[i]->getId() << " " << group->students[i]->getFio() << "\n";
            std::cin >> mark;
            group->students[i]->addmark(mark);
        }
    }
}
void Deanary::getStatistic() {
    for (int i = 0; i < count; i++) {
        std::cout << groups[i].title << " - " << groups[i].spec << std::endl;
        std::cout << "Students statistic:" << std::endl;
        for (int j = 0; j < groups[i].students.size(); j++) {
            double statictic = groups[i].students[j]->getAveragemark();
            std::cout << groups[i].students[j]->getFio() << " - "
                 << statictic << std::endl;
        }
        std::cout << "Group  statistic:" << groups[i].getAvaragemark() << std::endl;
    }
}
void Deanary::printGroups() {
    for (int i = 0;i < this->count;i++) {
        std::cout << groups[i].title << "\n" << groups[i].spec << "\n";
        for (int j = 0;j < groups[i].students.size();j++) {
            std::cout << groups[i].students[j]->getId() << " " << groups[i].students[j]->getFio() <<" - "<< join(groups[i].students[j]->marks) << "\n";
        }
        std::cout << "\n";
    }
}
Student* Deanary::findSudentId(int id_) {
    for (int i = 0;i < count;i++) {
        Student* student = groups[i].getStudent(id_);
        if (student != nullptr) {
            return student;
        }
    }
    return nullptr;
}
void Deanary::moveStudents(int id_, std::string gr) {
    bool head_flag = false;
    Student* student = findSudentId(id_);
    Group* now_group = student->group;
    int	new_group = 0;
    for (int i = 0;i < this->count;i++) {
        if (groups[i].getTitle() == gr) {
            new_group = i;
        }
    }
    if (student != nullptr)
    { 
        now_group->removeStudent(student);
        groups[new_group].addStudent(student);
    }
}
void Deanary::saveStaff(std::string file) {
    std::string res_data;
    for (int i = 0;i < count;i++) {
        res_data = res_data + groups[i].title + '\n' + groups[i].spec + '\n';
        for (int j = 0;j < groups[i].students.size();j++) {
            std::string mrks = join(groups[i].students[j]->marks);
            res_data = res_data + std::to_string(groups[i].students[j]->getId()) + " " + groups[i].students[j]->getFio() + " - " + mrks + "\n";
        }
        res_data += "***\n";
    }
    write_data(file, res_data);
}
void Deanary::initHeads() {
    for (int i = 0; i < count; i++) {
        groups[i].chooseHead();
        std::cout << groups[i].head->getFio() << " " << groups[i].spec<<"\n";
    }
}
void Deanary::fireStudents(double minMark) {
    for (int i = 0; i < count; i++) {
        for (int j = 0;j < groups[i].students.size();j++) {
            if (std::isgreaterequal(minMark, groups[i].students[j]->getAveragemark())) {
                 groups[i].removeStudent(groups[i].students[j]);
            }
        }
    }
}
