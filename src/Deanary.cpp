// Copyright 2020 Konina Tatiana
#include <stdlib.h>
#include<iostream>
#include <fstream>
#include "Deanary.h"
#include "Student.h"
#include "Group.h"
#include "Data.h"

double minAverege = 3.0;

Deanery::Deanery(std::string groups_list) {
  (*this).createGroups(groups_list);
}
Deanery::Deanery(std::string groups_list, std::string st_list) {
  (*this).createGroups(groups_list);
  (*this).hireStudent(st_list);
}
void Deanery::createGroups(std::string input) {
  std::vector<std::string> spec = read_spec(input);
  for (std::string str : spec) {
    specList.insert(std::pair<std::string, int>(str, 1));
    groups.push_back(new Group(str, 1));
  }
}

void Deanery::hireStudent(std::string input) {
  std::vector<std::map<std::string, std::string>> data = read_st(input);
  if (data.size()) {
    for (int i = 0; i < data.size(); ++i) {
      size_t pos = 0;
      std::vector<unsigned int> marks;
      while ((pos = data[i]["marks"].find(" ")) != std::string::npos) {
        marks.push_back(stoi(data[i]["marks"].substr(0, pos)));
        data[i]["marks"].erase(0, pos + 1);
      }
      marks.push_back(stoi(data[i]["marks"].substr(0, pos)));
      Student* st = new Student(stoi(data[i]["id"]),
        data[i]["fio"], marks, data[i]["spec"]);
      //  int randGroup = std::rand() % specList[data[i]["spec"]] + 1;
      int randGroup = 1;
      for (Group* group : groups) {
        if (group->getSpec() == st->getSpec() &&
          group->getTitle() == randGroup) {
          if (!group->addStudent(st)) {
            specList[data[i]["spec"]]++;
            Group* tmp = new Group(data[i]["spec"], randGroup);
            tmp->addStudent(st);
            groups.push_back(tmp);
          }
        }
      }
    }
  }
}

void Deanery::printGroups() const {
  for (Group* group : groups) {
    std::cout << group->getSpec() << " - " << group->getTitle() << std::endl;
    std::cout << "Students list:" << std::endl;
    for (std::pair<unsigned int, Student*> st : group->getStudents()) {
      if (st.second->isHeadOfGroup()) {
        std::cout << "Head: ";
      }
      std::cout << st.second->getFio() << std::endl;
    }
  }
}

void  Deanery::printStudents() const {
  for (Group* group : groups) {
    for (std::pair<unsigned int, Student*> st : group->getStudents()) {
      std::cout << st.second->getFio() << std::endl;
    }
  }
}

void Deanery::addMarksToAll(Group* group) const {
  for (std::pair<unsigned int, Student*> st : group->getStudents()) {
    unsigned int seed;
    int randomMark = std::rand() % 10;
    st.second->addMark(randomMark);
  }
}

bool Deanery::moveStudent(unsigned int id) {
  for (Group* group : groups) {
    if (Student* st = group->search(id)) {
      if (specList[st->getSpec()] != 1) {
        for (Group* newGroup : groups) {
          if (newGroup->getSpec() == st->getSpec() && newGroup->getTitle() ==
            group->getTitle() % specList[st->getSpec()] + 1) {
            group->removeStudent(id);
            st->addToGroup(newGroup);
          }
        }
      }
      return true;
    } else {
      continue;
    }
  }
  std::cout << "Student does not exist" << std::endl;
  return false;
}

void Deanery::fireStudents() {
  for (Group* group : groups) {
    for (std::pair<unsigned int, Student*> st : group->getStudents()) {
      if (st.second->getAverage() < minAverege) {
        group->removeStudent(st.second->getId());
      }
    }
  }
}

void Deanery::getStatistics() {
  for (Group* group : groups) {
    std::cout << group->getSpec() << " - " << group->getTitle() << std::endl;
    std::cout << "Students statictic:" << std::endl;
    for (std::pair<unsigned int, Student*> st : group->getStudents()) {
      double studentStatictic = st.second->getAverage();
      std::cout << st.second->getFio() << " - "
        << studentStatictic << std::endl;
    }
    std::cout << "Group  statictic:" << group->getAverageMarks() << std::endl;
  }
}

void Deanery::initHeads() {
  for (Group* group : groups) {
    if (group->getHead() == -1 && group->getGroupSize()) {
      group->chooseHead();
    }
  }
}
void Deanery::updateInfo(std::string output) const {
  std::string tmp = "";
  std::ofstream fout(output);
  for (Group* group : groups) {
    for (std::pair<unsigned int, Student*> st : group->getStudents()) {
      for (int mark : st.second->getMarks()) {
        tmp = tmp + std::to_string(mark) + " ";
      }
      tmp.pop_back();
      fout << "group:" << group->getTitle() << "," << "id:"
        << st.second->getId() << "," <<
        "fio:" << st.second->getFio() << "," << "marks:" << tmp << ","
        << "spec:" << group->getSpec() << ","
        << "group num:" << group->getTitle() << "," << "head:" <<
        st.second->isHeadOfGroup() << std::endl;
      tmp.clear();
    }
  }
  fout.close();
}
std::vector<Group*>Deanery::getGroups() {
  return groups;
}
Student* Deanery::findStudent(unsigned int id) {
  for (Group* group : groups) {
    if (Student* st = group->search(id)) {
      return st;
    } else {
      continue;
    }
  }
  std::cout << "Student does not exist" << std::endl;
  return nullptr;
}

