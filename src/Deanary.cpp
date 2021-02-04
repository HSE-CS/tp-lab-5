// Copyright 2021 soda

#include <fstream>
#include <string>
#include <iostream>
#include <json.hpp>
#include <sstream>
#include <ctime>
#include <Deanary.h>


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
        group->addStudent(student);
        student->addToGroup(group);
        student_num++;
    }
}


Deanary::Deanary() {
    groups = new std::vector<Group*>();
    moved_num = 0;
    fired_num = 0;
    createGroups();
    hireStudents();
    initHeads();
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
    std::cout << "Chosen of boss:" << std::endl;
    for (auto& group : *groups) {
        std::cout << group->getTitle() << " - " << group->getHead().getId()
            << ". " << group->getHead().getName() << ";" << std::endl;
    }
}

Group& Deanary::getGroup(const std::string& title) {
    for (Group* g : *groups) {
        if (g->getTitle() == title) {
            return *g;
        }
    }
}

void Deanary::addMarksToAll(int num_marks) {
    srand(time(0));
    for (int i = 0; i < num_marks; i++) {
        for (auto group : *groups) {
            for (auto student : *group->students) {
                int mark = 5 + ((student->getId()) % 10 - 5) + (rand() % 5);
                if (mark > 10) mark = 10;
                if (mark < 0) mark = 0;
                student->addmark(mark);
            }
        }
    }
}

Group& Deanary::GetGroupByStudent(int id) {
    for (auto& group : *groups) {
        for (auto& student : *group->students) {
            if (student->getId() == id) {
                return *group;
            }
        }
    }
}

Group& Deanary::GetGroupByStudent(const std::string& name) {
    for (auto& group : *groups) {
        for (auto& student : *group->students) {
            if (student->getName() == name) {
                return *group;
            }
        }
    }
}

void Deanary::moveStudents(int id, std::string& title) {
    Group& new_group = getGroup(title);
    Group& old_group = GetGroupByStudent(id);
    Student& student = old_group.getStudent(id);
    student.group->removeStudent(&student);
    new_group.addStudent(&student);
    student.addToGroup(&new_group);
    move_report(student, old_group, new_group);
}

void Deanary::moveStudents(std::string& name, std::string& title) {
    Group& new_group = getGroup(title);
    Group& old_group = GetGroupByStudent(name);
    Student& student = old_group.getStudent(name);
    student.group->removeStudent(&student);
    new_group.addStudent(&student);
    student.addToGroup(&new_group);
    move_report(student, old_group, new_group);
}

void Deanary::move_report(Student& student, Group& old, Group& _new) {
    moved_num++;
    std::cout << student.getName() << " move out "
        << old.getTitle() << " in " << _new.getTitle() << "." << std::endl;
}

void Deanary::fireStudents(int id) {
    Group& group = GetGroupByStudent(id);
    Student& student = group.getStudent(id);
    group.removeStudent(&student);
    fire_report(student);
    student_num--;
    delete& student;
}

void Deanary::fireStudents(std::string& name) {
    Group& group = GetGroupByStudent(name);
    Student& student = group.getStudent(name);
    group.removeStudent(&student);
    fire_report(student);
    student_num--;
    delete& student;
}

void Deanary::fire_report(Student& student) {
    fired_num++;
    std::cout << student.getName() << "was fired." << std::endl;
}

void Deanary::initHeads() {
    for (auto& group : *groups) {
        group->chooseHead();
    }
}

std::stringbuf Deanary::createStat() {
    std::stringbuf stat;
    std::ostream stream(&stat);
    stream << "Deanary statistick:\n";
    stream << "Students now - " << student_num << "\n";
    stream << "Students moved - " << moved_num << "\n";
    stream << "Students fired - " << fired_num << "\n";
    stream << "\n";
    for (auto& group : *groups) {
        stream << group->getTitle() << " [" << group->spec << "]\n";
        stream << "Num of students:\t" << group->students->size() << "\n";
        stream << "List of group:\n";
        for (auto& student : *group->students) {
            stream << student->getId() << ". " << student->getName() << ";\n";
        }
        stream << "\nAverage rating\t" << group->getAverageMark() << "\n";
        stream << "The best students (>6.5):\n";
        double averageMark;
        for (auto& student : *group->students) {
            averageMark = student->getAverageMark();
            if (averageMark > 6.5) {
                stream << student->getId() << ". " << student->getName()
                    << "\t " << averageMark << "\n";
            }
        }
        stream << "\nThe Dean's office wishes to expel (<3.5):\n";
        for (auto& student : *group->students) {
            averageMark = student->getAverageMark();
            if (averageMark < 3.5) {
                stream << student->getId() << ". " << student->getName()
                    << "\t " << averageMark << "\n";
            }
        }
        stream << "\n";
    }
    return stat;
}

void Deanary::printStat() {
    std::cout << createStat().str();
}

void Deanary::saveStuff() {
    std::ofstream file("statistic.txt");
    file << createStat().str();
}

void Deanary::fireWeakStudents() {
    for (auto& group : *groups) {
        double averageMark;
        std::cout << "\nThe Dean's office fired worst students:\n";
        for (auto& student : *group->students) {
            averageMark = student->getAverageMark();
            if (averageMark < 4.0) {
                std::cout << student->getId() << ". " << student->getName()
                    << "\t " << averageMark << "\n";
                fireStudents(student->getId());
            }
        }
    }
}

int Deanary::get_gr_num() {
    return group_num;
}

int Deanary::get_st_num() {
    return student_num;
}

int Deanary::get_mv_num() {
    return moved_num;
}

int Deanary::get_fi_num() {
    return fired_num;
}

Deanary::~Deanary() {
    for (auto group : *groups) {
        delete group;
    }
    delete groups;
}
