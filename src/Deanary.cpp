// Copyright 2021 mkhorosh
#include "Deanary.h"
#include <ctime>
#include<iostream>
#include <random>
// #include <stdlib.h>
// #include <chrono>
#include <fstream>

void Deanary::addMarksToAll() {
  for (auto &group : groups) {
    for (auto &student : group->students) {
//      srand(std::chrono::system_clock::now().time_since_epoch().count());
//      srand(time(0));
      std::default_random_engine generator;
      std::uniform_int_distribution<int> distribution(1,5);
      student->addMark(distribution(generator));  // max mark is 5
      student->addMark(distribution(generator));
      student->addMark(distribution(generator));
    }
  }
}
void Deanary::getStatistics() {
  std::cout << std::endl;
  double min = 6;
  double max = -1;
  for (auto &group : groups) {
    for (auto &student : group->students) {
      if (student->getAverageMark() < min) {
        min = student->getAverageMark();
      }
      if (student->getAverageMark() > max) {
        max = student->getAverageMark();
      }
    }
  }
  std::cout << "Best students:" << std::endl;
  for (auto &group : groups) {
    for (auto &student : group->students) {
      if (student->getAverageMark() == max) {
        std::cout << student->id << '\t' <<
        student->fio << '\t' << max << std::endl;
      }
    }
  }
  std::cout << "Worst students:" << std::endl;
  for (auto &group : groups) {
    for (auto &student : group->students) {
      if (student->getAverageMark() == min) {
        std::cout << student->id << '\t' <<
        student->fio << '\t' << min << std::endl;
      }
    }
  }
}
void Deanary::moveStudent(std::string id, std::string group) {
  int stpos = 0;
  int currentgr = 0;
  int newgr = 0;
  for (int i = 0; i < this->groups.size(); i++) {
    for (int j = 0; j < groups[i]->students.size(); j++) {
      if (groups[i]->students[j]->id == id) {
        stpos = j;
        currentgr = i;
      }
    }
  }
  for (int i = 0; i < this->groups.size(); i++) {
    if (groups[i]->title == group) {
      newgr = i;
    }
  }
  Student *st = this->groups[currentgr]->students[stpos];
  if (st != nullptr) {
    this->groups[currentgr]->removeStudent(st->id);
    this->groups[newgr]->addStudent(st);
  }
}
void Deanary::saveStaff(std::string outfile) {
  std::ofstream out;          // поток для записи
  out.open(outfile);  // окрываем файл для записи
  if (out.is_open()) {
    for (auto &group : groups) {
      out << group->title << ' ' << group->spec << std::endl;
      for (auto &student : group->students) {
        out << '\t' << student->id << ' ' << student->fio
        << ' ' << student->getAverageMark() << std::endl;
      }
    }
  }
  out.close();
}
void Deanary::initHeads() {
  for (auto &group : groups) {
    group->chooseHead();
  }
}
void Deanary::fireStudents() {
  double inappropriate = 3.0;  // fire everyone 3.0 and less
  for (auto &group : groups) {
    for (auto &student : group->students) {
      if (student->getAverageMark() <= inappropriate) {
        if (student->group != nullptr) {
          student->group->removeStudent(student->id);
        }
      }
    }
  }
}
void Deanary::printData() {
  std::cout << std::endl;
  for (auto &group : groups) {
    std::cout << group->title << ' ' << group->spec <<
    std::endl;
    for (auto &student : group->students) {
      std::cout << '\t' << student->id << ' ' <<
      student->fio << ' ' << student->getAverageMark() << std::endl;
    }
  }
}
void Deanary::createGroups(std::vector<std::string> titles,
                           std::vector<std::string> specs) {
  for (int i = 0; i < titles.size(); i++) {
    Group *gr = new Group(titles[i], specs[i]);
    this->groups.push_back(gr);
  }
}
void Deanary::hireStudents(std::vector<std::string> fios,
                           std::vector<std::string> ids) {
  srand(time(0));
  for (int i = 0; i < fios.size(); i++) {
    Student *st = new Student(ids[i], fios[i]);
    this->groups[rand() % this->groups.size()]->addStudent(st);
  }
}
