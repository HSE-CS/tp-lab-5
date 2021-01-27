// Copyright 2020 Stanislav Stoianov

#include "../include/Deanary.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <filesystem>
#include <cstring>
#include <fstream>
#include <iterator>

void Deanery::createGroups(char *dirpath) {
  setlocale(LC_ALL, "rus");
  for (const auto &entry : std::filesystem::directory_iterator(dirpath)) {
    const std::filesystem::path &path = entry.path();
    if (path.extension() == ".csv") {
      std::string title = path.filename().filename();
      title.erase(title.find_last_not_of(".csv") + 1);
      if (title.find('-') != std::string::npos) {
        std::string spec = title.substr(title.find('-') + 1);
        auto *group = new Group(strtok(title.data(), "-"), spec);
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
      for (int i = 0; i < rand() % 10 + 5; ++i) {
        s->addMark(rand() % 10);
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
      string = g->getTitle() + "-" + g->getSpec() + "-" + std::to_string(g->getAverageMark());
    }
    string += ".csv";
    out.open(std::string(dirpath) + "/" + string);
    out << "id,fullname,marks,averagemark" << std::endl;
    for (Student *s : g->getStudents()) {
      std::stringstream result;
      std::copy(s->getMarks().begin(), s->getMarks().end(),
                std::ostream_iterator<int>(result, ";"));
      out << std::to_string(s->getId()) + "," + s->getFullname() + "," + result.str() + ","
          + std::to_string(s->getAverageMark()) << std::endl;
    }
  }
}

void Deanery::moveStudents(Group *fromGroup, Group *toGroup) {
  for (Student *s: fromGroup->getStudents()) {
    s->addToGroup(toGroup);
  }
}

void Deanery::fireStudents(int lowMark) {
  for (Group *g : this->groups) {
    for (Student *s : g->getStudents()) {
      if (s->getAverageMark() < lowMark) {
        s->addToGroup(nullptr);
      }
    }
  }
}

void Deanery::saveStaff(char *filepath) {
  setlocale(LC_ALL, "rus");
  // todo
}

void Deanery::initHeads() {
  for (Group *g : this->groups) {
    g->chooseHead(g->getStudents()
                      .at(rand() % g->getStudents().size()));
  }
}

void Deanery::getStatistics() {
  // todo
}

const std::vector<Group *> &Deanery::getGroups() const {
  return this->groups;
}
