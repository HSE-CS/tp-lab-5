// Copyright 2020 Stanislav Stoianov

#include "../include/Deanary.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <filesystem>
#include <cstring>

void Deanery::createGroups(char *filepath) {
  setlocale(LC_ALL, "rus");
  for (const auto &entry : std::filesystem::directory_iterator(filepath)) {
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

void Deanery::hireStudents(char *filepath) {
  setlocale(LC_ALL, "rus");
}

void Deanery::addMarksToAll() {
  for (Group *g : groups) {
    for (Student *s : g->getStudents()) {
      s->addMark(rand() % 10);
    }
  }
}

void Deanery::getStatistics(char *filepath) {
  setlocale(LC_ALL, "rus");
}

void Deanery::moveStudents(Group *fromGroup, Group *toGroup) {
  for (Student *s: fromGroup->getStudents()) {
    s->addToGroup(toGroup);
  }
}

void Deanery::fireStudents(int lowMark) {
  for (Group *g : groups) {
    for (Student *s : g->getStudents()) {
      if (s->getAverageMark() < lowMark) s->addToGroup(nullptr);
    }
  }
}

void Deanery::saveStaff(char *filepath) {
  setlocale(LC_ALL, "rus");
}

void Deanery::initHeads() {
  for (Group *g : groups) {
    g->chooseHead(g->getStudents()
                      .at(rand() % g->getStudents().size()));
  }
}

void Deanery::getStatistics() {

}

const std::vector<Group *> &Deanery::getGroups() const {
  return groups;
}
