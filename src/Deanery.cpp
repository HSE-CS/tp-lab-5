#include <fstream>
#include <nlohmann/json.hpp>
#include <chrono>
#include <string>
#include <iostream>
#include <sstream>
#include "Deanery.h"

void Deanery::createGroups() {
  std::string groups_file_path = R"(./data/Groups.json)";
  std::ifstream i(groups_file_path);
  nlohmann::json j;
  i >> j;
  i.close();
  auto groups_json = j.get<std::vector<nlohmann::json>>();
  for (const auto& v : groups_json) {
    auto title = v["title"].get<std::string>();
    auto spec = v["spec"].get<std::string>();
    auto *_g = new Group(title, spec);
    groups->push_back(_g);
  }
}

void Deanery::hireStudents() {

    std::string students_file_path = R"(./data/Students.json)";
    std::ifstream i(students_file_path);
    nlohmann::json j;
    i >> j;
    i.close();
    auto students = j.get<std::vector<std::string>>();
    for (auto v : students) {
        std::cout << 1 << "\n";
        auto *student = new Student(id++, v);
        std::cout << student->getName() << "\n";
        Group *g = groups->at(rand() % groups->size());
        std::cout << g->getTitle() << "\n";
        g->addStudent(*student);
        std::cout << 4 << "\n";
        student->addToGroup(g);
        std::cout << 5 << "\n";
    }
}

void Deanery::addMarksToAll(int cnt) {
    for (int i = 0; i < cnt; i++){
        for (auto group : *groups) {
            for (auto student : *group->students){
                student->addmark(rand() % 10 + 1);
            }
        }
    }
}

void Deanery::initHeads() {
    for (auto &group : *groups) {
        group->chooseHead();
    }
}

Group &Deanery::getGroup(const std::string &title) {
    for (Group *g : *groups) {
        if (g->getTitle() == title) {
            return *g;
        }
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

void Deanery::moveStudent(int _id, std::string &title) {
    Group &new_group = getGroup(title);
    Group &old_group = groupByStudent(_id);
    Student &student = old_group.getStudent(_id);
    student.group->removeStudent(student);
    new_group.addStudent(student);
    student.addToGroup(&new_group);
    std::cout << "Student " << student.getName() << " was move from \""
    << old_group.getTitle() << "\" to \"" << title << "\"." << std::endl;
}

void Deanery::moveStudent(std::string& name, std::string &title) {
    Group &new_group = getGroup(title);
    Group &old_group = groupByStudent(name);
    Student &student = old_group.getStudent(name);
    student.group->removeStudent(student);
    new_group.addStudent(student);
    student.addToGroup(&new_group);
    std::cout << "Student " << student.getName() << " was move from \""
    << old_group.getTitle() << "\" в группу \"" << title << "\"." << std::endl;
}

void Deanery::fireStudents(int _id) {
    Group &group = groupByStudent(_id);
    Student &student = group.getStudent(_id);
    group.removeStudent(student);
    std::cout << "Student " << student.getName()
    << " fired." << std::endl;
    delete &student;
}

void Deanery::fireStudents(std::string &name) {
    Group &group = groupByStudent(name);
    Student &student = group.getStudent(name);
    group.removeStudent(student);
    std::cout << "Student " << student.getName()
              << " fired." << std::endl;
    delete &student;
}

void Deanery::getStatistics() {
   for (auto &group : *groups) {
       std::cout << "Group \"" << group->getTitle()
       << " (" << group->spec << ")\n";
       std::cout << "Student amount:\t" << group->students->size() << "\n";
       for (auto &student : *group->students) {
           std::cout << student->getName() << " " << student->getId();
       }
       std::cout << "\n Average mark:\t"
       << group->getAveragemark() << "\n";


       std::cout << "Fire recommended :\n";
       for (auto &student : *group->students) {
           float averageMark = student->getAveragemark();
           if (averageMark < 3.5) {
               std:: cout << student->getName() << " " << student->getId() << "]\t"
                      << " " << averageMark << "\n";
           }
       }
       std::cout << "\n";
   }
}

Deanery::Deanery() {
    id = 0;
    groups = new std::vector<Group *>();
    createGroups();
    std::cout << "Groups created " << groups->size() << "\n";
    for (auto &group : *groups) {
        std::cout << group->getTitle() << " " << group->spec << "\n";
    }
    std::cout << "\n";

    std::cout << "Hired students:" << "\n";
    hireStudents();
    for (auto &group : *groups) {
        std::cout << group->getTitle() << ": "
                  << group->students->size() << "\n";
    }
    std::cout << "\n";
    initHeads();
    std::cout << "Heads was choosen:" << "\n";
    for (auto &group : *groups) {
        std::cout << group->getTitle() << ": " << group->getHead()->getName()
                  << " " << group->getHead()->getId() << "\n";
    }
}
