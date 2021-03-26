// Copyright 2021 PaninaPolina
#include "Student.h"
#include "Group.h"
#include "Deanary.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

Deanery::Deanery(std::string NameStudents, std::string NameGroups) {
  fileStudents = NameStudents;
  fileGroups = NameGroups;
}

void Deanery::CreateStudents() {
  std::ifstream file(fileStudents);
  std::string fioStudent;
  int id = 100;
  while (getline(file, fioStudent)) {
    id++;
    students.push_back(new Student(id, fioStudent));
  }
  file.close();
  numSt = students.size();
}

void Deanery::CreateGroups() {
  std::ifstream file(fileGroups);
  std::string nameGroup;
  while (getline(file, nameGroup)) {
    groups.push_back(new Group(nameGroup));
  }
  file.close();

  numGr = groups.size();

  int numinGr =
      numSt / numGr;
  for (int i = 0; i < numGr; i++) {
    for (int j = i * numinGr; j < (i + 1) * numinGr; j++) {
      students[j]->enterGroup(groups[i]);
      groups[i]->addStudent(students[j]);
    }
  }
  int extraSt = numSt % numGr;
  for (int j = 0; j < extraSt; j++) {
    students[numinGr * numGr + j]->enterGroup(
        groups[numGr - 1]);
    groups[numGr - 1]->addStudent(students[numinGr * numGr + j]);
  }
}

void Deanery::addMarks() {
  int mark;
  for (int i = 0; i < numSt; i++) {
    for (int n = 0; n < 8; n++) {
      mark = std::rand() % 10 + 1;
      students[i]->addMark(mark);
    }
  }
}

void Deanery::changeGroup(std::string nameSt, std::string nameNewGr) {
  for (int i = 0; i < numSt; i++) {
    if (students[i]->fio == nameSt) {
      for (int k = 0; k < numGr; k++) {
        if (groups[k]->title == nameNewGr) {
          Group* presentGr = students[i]->group;
          students[i]->enterGroup(groups[k]);
          groups[k]->addStudent(students[i]);
          presentGr->exceptionStudent(
              students[i]->fio);
        }
      }
    }
  }
}

void Deanery::exceptionStudent() {
  for (int i = 0; i < numSt; i++) {
    if (students[i]->averageMark() < 4) {
      students[i]->group->exceptionStudent(
          students[i]->fio);
      students.erase(students.begin() + i);
      numSt--;
      i--;
    }
  }
}

void Deanery::electGhead() {
  for (int i = 0; i < numGr; i++) {
    groups[i]->electHead();
  }
}

void Deanery::getStatistics(std::string name) {
  for (int i = 0; i < numSt; i++) {
    StStat.push_back(
        std::pair<float, std::string>(students[i]->averageMark(),
            students[i]->fio));
  }
  sort(StStat.begin(), StStat.end());

  for (int j = 0; j < numGr; j++) {
    GrStat.push_back(
        std::pair<float, std::string>(groups[j]->averageGroup(),
            groups[j]->title));
  }
  sort(GrStat.begin(), GrStat.end());

  std::ofstream file;
  file.open(name);
  if (file.is_open()) {
    for (int j = 0; j < StStat.size(); j++) {
      file << StStat[j].second << "-" << StStat[j].first << std::endl;
    }
    for (int i = 0; i < GrStat.size(); i++) {
      file << GrStat[i].second << "  -  " << GrStat[i].first << std::endl;
    }
  }
  file.close();
}

void Deanery::update(std::string name) {
  std::ofstream file;
  file.open(name);

  if (file.is_open()) {
    file << "Number of students is  " << numSt << std::endl;
    for (int i = 0; i < numGr; i++) {
      file << "In " << groups[i]->title << " " << groups[i]->num << " people. "
           << " Average score of the group: "
          << groups[i]->averageGroup() << std::endl;
      file << "Average score of the group: " << groups[i]->head->fio
          << std::endl;
      for (int j = 0; j < groups[i]->students.size(); j++) {
        file << groups[i]->students[j]->fio << "-"
             << groups[i]->students[j]->averageMark() << "   ";
        for (int h = 0; h < groups[i]->students[j]->marks.size(); h++) {
          file << groups[i]->students[j]->marks[h] << " ";
        }
        file << std::endl;
      }
      file << std::endl;
    }
  }
  file.close();
}

void Deanery::printinfo() {
  std::cout << "Number of students is  " << numSt << std::endl;

  for (int i = 0; i < numGr; i++) {
    std::cout << "In " << groups[i]->title << " " << groups[i]->num
              << " people. "
              << " Average score of the group: "
        << groups[i]->averageGroup() << std::endl;
    std::cout << "Average score of the group: " << groups[i]->head->fio
        << std::endl;
    for (int j = 0; j < groups[i]->students.size(); j++) {
      std::cout << groups[i]->students[j]->fio << "-"
           << groups[i]->students[j]->averageMark() << "    ";
      for (int h = 0; h < groups[i]->students[j]->marks.size(); h++) {
        std::cout << groups[i]->students[j]->marks[h] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  std::cout << std::endl << "Statistics" << std::endl;
  for (int j = 0; j < StStat.size(); j++) {
    std::cout << StStat[j].second << "-" << StStat[j].first << std::endl;
  }

  for (int i = 0; i < GrStat.size(); i++) {
    std::cout << GrStat[i].second << "  -  " << GrStat[i].first << std::endl;
  }
}
