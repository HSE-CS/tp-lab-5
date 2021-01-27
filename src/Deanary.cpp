// Copyright 2020 Stanislav Stoianov

#include "../include/Deanary.h"
#include <string>
#include <iostream>
#include <filesystem>
#include <cstring>
#include <fstream>
#include <iterator>
#include <random>

static std::mt19937_64 rng;

void Deanery::createGroups(char *dirpath) {
  setlocale(LC_ALL, "rus");
  for (const auto &entry : std::filesystem::directory_iterator(dirpath)) {
    const std::filesystem::path &path = entry.path();
    if (path.extension() == ".csv") {
      std::string title = path.filename().filename();
      title.erase(title.find_last_not_of(".csv") + 1);
      if (title.find('-') != std::string::npos) {
        std::string spec = title.substr(title.find('-') + 1);
        auto *group = new Group(title.substr(0, title.find('-')), spec);
        this->groups.push_back(group);
      } else {
        auto *group = new Group(title);
        this->groups.push_back(group);
      }
    }
  }
}

void Deanery::hireStudents(Group *group, char *filepath) {
  setlocale(LC_ALL, "rus");
  std::string string;
  std::ifstream file(filepath);
  getline(file, string);
  while (getline(file, string)) {
    auto *s = new Student(std::stoi(string.substr(0, string.find(','))),
                          string.substr(string.find(',') + 1));
    group->addStudent(s);
  }
  file.close();
}

void Deanery::addMarksToAll() {
  for (Group *g : this->groups) {
    for (Student *s : g->getStudents()) {
      for (int i = 0; i < rng() % 10 + 5; ++i) {
        s->addMark(rng() % 10);
      }
    }
  }
}

void Deanery::getStatistics(char *dirpath) {
  setlocale(LC_ALL, "rus");
  for (Group *g : this->groups) {
    std::ofstream out;
    std::string string;
    if (g->getSpec().empty()) {
      string = g->getTitle() + "-" + std::to_string(g->getAverageMark());
    } else {
      string = g->getTitle() + "-"
          + g->getSpec() + "-"
          + std::to_string(g->getAverageMark());
    }
    string += ".csv";
    out.open(std::string(dirpath) + "/" + string);
    out << "id,fullname,marks,averagemark" << std::endl;
    for (Student *s : g->getStudents()) {
      std::stringstream result;
      std::copy(s->getMarks().begin(), s->getMarks().end(),
                std::ostream_iterator<int>(result, ";"));
      out << std::to_string(s->getId()) + ","
          + s->getFullname() + ","
          + result.str() + ","
          + std::to_string(s->getAverageMark()) << std::endl;
    }
    out.close();
  }
}

void Deanery::moveStudents(Group *fromGroup, Group *toGroup) {
  std::vector<Student *> fromStudent = fromGroup->getStudents();
  for (auto &i : fromStudent) {
    toGroup->addStudent(i);
  }
  fromGroup->getStudents().clear();
  delete fromGroup;
}

void Deanery::fireStudents(int lowMark) {
  for (Group *g : this->groups) {
    for (Student *s : g->getStudents()) {
      if (s->getAverageMark() < lowMark) {
        g->removeStudent(s);
      }
    }
  }
}

void Deanery::saveStaff(char *dirpath) {
  setlocale(LC_ALL, "rus");
  for (Group *g : this->getGroups()) {
    std::ofstream out;
    std::string string;
    if (g->getSpec().empty()) {
      string = g->getTitle();
    } else {
      string = g->getTitle() + "-" + g->getSpec();
    }
    string += ".csv";
    out.open(std::string(dirpath) + "/" + string);
    out << "id,fullname" << std::endl;
    for (Student *s : g->getStudents()) {
      out << std::to_string(s->getId()) + ","
          + s->getFullname() << std::endl;
    }
    out.close();
  }
}

void Deanery::initHeads() {
  for (Group *g : this->groups) {
    g->chooseHead(g->getStudents()
                      .at(rng() % g->getStudents().size()));
  }
}

void Deanery::getStatistics() {
  setlocale(LC_ALL, "rus");
  for (Group *g : this->groups) {
    std::string string;
    if (g->getSpec().empty()) {
      string = g->getTitle() + "-"
          + std::to_string(g->getAverageMark());
    } else {
      string = g->getTitle() + "-"
          + g->getSpec() + "-"
          + std::to_string(g->getAverageMark());
    }
    string += ".csv";
    std::cout << string << std::endl;
    std::cout << "id,fullname,marks,averagemark" << std::endl;
    for (Student *s : g->getStudents()) {
      std::stringstream result;
      std::copy(s->getMarks().begin(), s->getMarks().end(),
                std::ostream_iterator<int>(result, ";"));
      std::cout << std::to_string(s->getId()) + ","
          + s->getFullname() + ","
          + result.str() + ","
          + std::to_string(s->getAverageMark()) << std::endl;
    }
  }
}

std::vector<Group *> &Deanery::getGroups() {
  return this->groups;
}
