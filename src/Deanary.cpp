//
// Created by mushka on 19.03.2021.
//

#include "../include/Deanary.h"

#include <utility>

void Deanary::CreateGroup(std::string new_title, std::string new_spec) {
    groups.push_back(new Group(std::move(new_title), std::move(new_spec)));
}

void Deanary::CreateStudent(std::string new_fio, Group *group) {
    group->AddStudent(new Student(studentsNum, std::move(new_fio)));
    studentsNum++;
}

Group * Deanary::GroupByTitle(const std::string &title) {
    for (auto & group : groups) {
        if (group->GetTitle() == title) {
            return group;
        }
    }
    return nullptr;
}