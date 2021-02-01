// Copyright 2021 valvarl

#include "Deanery.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <nlohmann/json.hpp>


void Deanery::createGroups() {
    std::string g = R"(groups.json)";
    std::ifstream ig(g);
    nlohmann::json jg;
    ig >> jg;
    ig.close();
    auto groups_json = jg.get<std::vector<nlohmann::json>>();
    for (const auto& v : groups_json) {
        auto title = v["title"].get<std::string>();
        auto spec = v["spec"].get<std::string>();
        auto *_g = new Group{&title, &spec, *this};
        groups->push_back(_g);
    }
}

void Deanery::hireStudents() {
    std::string s = R"(students.json)";
    std::ifstream is(s);
    nlohmann::json js;
    is >> js;
    is.close();
    auto students = js.get<std::vector<std::string>>();
    std::string title;
    for (auto v : students) {
        auto *student = new Student{id++, v};
        Group *g = groups->at(rand_int() % groups->size());
        g->addStudent(student);
        student->addToGroup(g);
    }
}

Group &Deanery::groupByStudent(int _id) {
    for (auto &group : *groups) {
        for (auto &student : *group->students) {
            if (student->getId() == _id) {
                return *group;
            }
        }
    }
}

Group &Deanery::groupByStudent(const std::string& name) {
    for (auto &group : *groups) {
        for (auto &student : *group->students) {
            if (student->getName() == name) {
                return *group;
            }
        }
    }
}

Deanery::Deanery() {
    id = 0;
    groups = new std::vector<Group *>();
//    simple_rand.seed(
//            std::chrono::system_clock::now().time_since_epoch().count());
    simple_rand.seed(42);  // предсказуемый рандом
    createGroups();
    std::cout << "Групп создано [" << groups->size() << "]:" << std::endl;
    for (auto &group : *groups) {
        std::cout << group->getTitle() << " [" << group->spec << "] ";
    }
    std::cout << std::endl << std::endl;
    hireStudents();
    std::cout << "Студентов зачислено:" << std::endl;
    for (auto &group : *groups) {
        std::cout << group->getTitle() << ": "
                  << group->students->size() << std::endl;
    }
    std::cout << std::endl;
    initHeads();
    std::cout << "Выбраны старостами:" << std::endl;
    for (auto &group : *groups) {
        std::cout << group->getTitle() << ": " << group->getHead().getName()
                  << "[" << group->getHead().getId() << "]" << std::endl;
    }
    std::cout << std::endl << "Инициализация завершена." << std::endl;
}

void Deanery::addMarksToAll(int amount) {
    for (int i = 0; i < amount; i++) {
        for (auto group : *groups) {
            for (auto student : *group->students) {
                student->addmark(4 + rand_int() % 7 -
                                 2 * (rand_int() % 2) - rand_int() % 3);
            }
        }
    }
}

std::stringbuf Deanery::generateStatistic() {
    std::stringbuf str;
    std::ostream stream(&str);
    for (auto &group : *groups) {
        stream << "Группа \"" << group->getTitle()
        << " [" << group->spec << "]\n";
        stream << "Количество студентов:\t" << group->students->size() << "\n";
        for (auto &student : *group->students) {
            stream << student->getName() << "[" << student->getId() << "] ";
        }
        stream << "\nСредний балл в группе:\t"
        << group->getAverageMark() << "\n";
        stream << "Претенденты на красный диплом:\n";
        double averageMark;
        for (auto &student : *group->students) {
            averageMark = student->getAverageMark();
            if (averageMark >= 7.5) {
                stream << student->getName() << "[" << student->getId() << "]\t"
                << " " << averageMark << "\n";
            }
        }
        stream << "Рекомендованы к отчислению:\n";
        for (auto &student : *group->students) {
            averageMark = student->getAverageMark();
            if (averageMark < 4) {
                stream << student->getName() << "[" << student->getId() << "]\t"
                       << " " << averageMark << "\n";
            }
        }
        stream << "\n";
    }
    return str;
}

void Deanery::getStatistics() {
    std::cout << generateStatistic().str();
}

void Deanery::moveStudents(int _id, const std::string &title) {
    Group &group = getGroup(title);
    Group &old_group = groupByStudent(_id);
    Student &student = old_group.getStudent(_id);
    student.group->removeStudent(&student);
    group.addStudent(&student);
    student.addToGroup(&group);
    std::cout << "Студент " << student.getName() << " переведен из группы \""
    << old_group.getTitle() << "\" в группу \"" << title << "\"." << std::endl;
}

void Deanery::moveStudents(const std::string& name, const std::string &title) {
    Group &group = getGroup(title);
    Group &old_group = groupByStudent(name);
    Student &student = old_group.getStudent(name);
    student.group->removeStudent(&student);
    group.addStudent(&student);
    student.addToGroup(&group);
    std::cout << "Студент " << student.getName() << " переведен из группы \""
    << old_group.getTitle() << "\" в группу \"" << title << "\"." << std::endl;
}

void Deanery::saveStuff() {
    std::string s = R"(statistic.txt)";
    std::ofstream file(s);
    file << generateStatistic().str();
}

void Deanery::initHeads() {
    for (auto &group : *groups) {
        group->chooseHead();
    }
}

void Deanery::fireStudents(int _id) {
    Group &group = groupByStudent(_id);
    Student &student = group.getStudent(_id);
    group.removeStudent(&student);
    std::cout << "Студент " << student.getName()
    << " был отчислен." << std::endl;
    delete &student;
}

void Deanery::fireStudents(const std::string& name) {
    Group &group = groupByStudent(name);
    Student &student = group.getStudent(name);
    group.removeStudent(&student);
    std::cout << "Студент " << student.getName()
              << " был отчислен." << std::endl;
    delete &student;
}

Group &Deanery::getGroup(const std::string &title) {
    for (Group *g : *groups) {
        if (g->getTitle() == title) {
            return *g;
        }
    }
}

Deanery::~Deanery() {
    for (auto group : *groups) {
        delete group;
    }
    delete groups;
}

std::vector<Group *> *Deanery::getGroups() const {
    return groups;
}
