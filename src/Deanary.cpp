// Copyright 2021 soda

#include <fstream>
#include <string>
#include <iostream>
#include "json.hpp"
#include "json.h"
#include <sstream>
#include <ctime>
#include "Deanary.h"


using json = nlohmann::json;

void Deanary::createGroups() {
    std::ifstream i("groups.json");
    json json_group;
    i >> json_group;
    i.close();
    auto groups_json = json_group.get<std::vector<json>>();
    group_num = 0;
    for (const auto& index : groups_json) {
        auto Title = index["Title"].get<std::string>();
        auto Spec = index["Spec"].get<std::string>();
        auto* group = new Group{ Title, Spec, *this };
        groups->push_back(group);
        group_num++;
    }
}

void Deanary::hireStudents() {
    std::ifstream i("students.json");
    json json_students;
    i >> json_students;
    i.close();
    auto students = json_students.get<std::vector<std::string>>();
    std::string title;
    srand(time(0));
    int student_id = 0;
    student_num = 0;
    for (auto index : students) {
        auto* student = new Student{ student_id++, index };
        Group* group = groups->at(rand() % group_num);
        group->addStudent(*student);
        student->addToGroup(group);
        student_num++;
    }
}


Deanary::Deanary() {
    groups = new std::vector<Group*>();
    createGroups();
    hireStudents();
    get_create_inf();
}

void Deanary::get_create_inf() {
    std::cout << "Groups created - " << group_num << "." << std::endl;
    std::cout << "List of groups: " << std::endl;
    for (auto& group : *groups) {
        std::cout << group->getTitle() << " - "
            << group->spec << "." << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Students hired - " << student_num << std::endl;
    std::cout << "For ways: " << std::endl;
    for (auto& group : *groups) {
        std::cout << group->getTitle() << " - "
            << group->students->size() << std::endl;
    }
}

Group& Deanary::getGroup(const std::string& title) {
    for (Group* g : *groups) {
        if (g->getTitle() == title) {
            return *g;
        }
    }
}

Deanary::~Deanary() {
    for (auto group : *groups) {
        delete group;
    }
    delete groups;
}