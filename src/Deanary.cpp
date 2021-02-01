// Copyright 2021 VadMack



#include <fstream>
#include <iostream>
#include "Group.h"
#include "Deanary.h"
#define SIZE1 3
#define SIZE2 30

void Deanary::createGroups() {
  std::string line;
  std::ifstream in("Groups.txt");
  if (in.is_open()) {
    while (getline(in, line)) {
      std::string title;
      std::string specialization;
      int i = 0;
      while (line[i] != ',') {
        title.push_back(line[i]);
        i++;
      }
      i++;
      i++;  //  space skip
      while (line[i] != ';') {
        specialization.push_back(line[i]);
        i++;
      }
      this->groups.reserve(groups.size() + 1);
      this->groups.push_back(new Group(title, specialization));
    }
  }
  in.close();
}

std::vector<Student *> Deanary::createStudents() {
  std::vector < Student * > students;

  std::string line;
  std::ifstream in("Students.txt");
  if (in.is_open()) {
    while (getline(in, line)) {
      std::string id;
      std::string name;
      int i = 0;
      while (line[i] != ',') {
        id.reserve(id.size() + 1);
        id.push_back(line[i]);
        i++;
      }
      i++;
      i++;  //  space skip
      while (line[i] != ',') {
        name.reserve(name.size() + 1);
        name.push_back(line[i]);
        i++;
      }

      students.reserve(students.size() + 1);
      students.push_back(new Student(id, name));
    }
  }
  in.close();
  return students;
}

/*void Deanary::createGroups() {
  Group *groups[SIZE1];
  for (int i = 0; i < SIZE1; ++i) {
    groups[i] = new Group("", "");
  }
  int index = 0;

  std::string line;
  std::ifstream in("Groups.txt");
  if (in.is_open()) {
    while (getline(in, line)) {
      std::string title;
      std::string specialization;
      int i = 0;
      while (line[i] != ',') {
        title.push_back(line[i]);
        i++;
      }
      i++;
      i++;  //  space skip
      while (line[i] != ';') {
        specialization.push_back(line[i]);
        i++;
      }
      //  std::cout << id << " --- " << name << std::endl;
      groups[index]->setTitle(title);
      groups[index]->setSpecialization(specialization);
      index++;
    }
  }
  in.close();

  this->groups = new Group*[16];
  for (int i = 0; i < sizeof(groups); ++i) {
    this->groups[i] = groups[i];
  }
}*/

/*std::vector<Student *> Deanary::createStudents() {
  Student **students = new Student*[SIZE2];

  for (int i = 0; i < SIZE2; ++i) {
    students[i] = new Student("", "");
  }
  int index = 0;

  std::string line;
  std::ifstream in("Students.txt");
  if (in.is_open()) {
    while (getline(in, line)) {
      std::string id;
      std::string name;
      int i = 0;
      while (line[i] != ',') {
        id.reserve(id.size() + 1);
        id.push_back(line[i]);
        i++;
      }
      i++;
      i++;  //  space skip
      while (line[i] != ',') {
        name.reserve(name.size() + 1);
        name.push_back(line[i]);
        i++;
      }
      //  std::cout << id << " --- " << name << std::endl;
      //students[i] = new Student(id, name);
      students[index]->setId(id);
      students[index]->setFio(name);
      index++;
    }
  }
  in.close();
  return students;
}*/

void Deanary::moveStudents(std::vector<Student *> students,
                           Group *from,
                           Group *to) {
  for (int i = 0; i < SIZE2 / 3; ++i) {
    from->removeStudent(students[i]);
    to->addStudent(students[i]);
  }
}
const std::vector<Group *> &Deanary::getGroups() const {
  return groups;
}

void Deanary::addRandomMarksToAll() {
  unsigned int seed;
  for (int i = 0; i < this->groups.size(); ++i) {
    for (int j = 0; j < this->getGroups().at(i)->getStudents().size(); ++j) {
      this->getGroups().at(i)->getStudents().at(j)->addMark(rand_r(&seed) % 11);
    }
  }
}

void Deanary::initHeads() {
  unsigned int seed;
  for (int i = 0; i < this->groups.size(); ++i) {
    int sizeOfArrOfSt = this->getGroups().at(i)->getStudents().size();
    if (sizeOfArrOfSt >= 1) {
      this->getGroups().at(i)->chooseHead(this->getGroups().at(i)->
          getStudents().at(rand_r(&seed) % sizeOfArrOfSt));
    }
  }
}

void Deanary::getStatistics() {
  for (int i = 0; i < this->groups.size(); ++i) {
    std::string title = this->getGroups().at(i)->GetTitle();
    std::string spec = this->getGroups().at(i)->getSpecialization();
    double avrGr = this->getGroups().at(i)->calculateAverageMark();
    std::cout << title << " -- " << spec << std::endl;
    std::cout << "Average mark of the group: " << avrGr << std::endl;
    std::cout << "Head: " <<
              this->getGroups().at(i)->getHead()->getFio() << std::endl;
    std::cout << "{" << std::endl;
    for (int j = 0; j < this->getGroups().at(i)->getStudents().size(); ++j) {
      std::string id = this->getGroups().at(i)->getStudents().at(j)->getId();
      std::string name = this->getGroups().at(i)->getStudents().at(j)->getFio();
      double avr = this->getGroups().at(i)->getStudents().at(j)->
          calculateAverageMark();
      std::cout << id << " --- " << name <<
                " --- average: " << avr << std::endl;
    }
    std::cout << "}" << std::endl;
  }
}

void Deanary::saveStaff() {
  std::ofstream out;
  out.open("Statistics.txt");
  if (out.is_open()) {
    for (int i = 0; i < this->groups.size(); ++i) {
      std::string title = this->getGroups().at(i)->GetTitle();
      std::string spec = this->getGroups().at(i)->getSpecialization();
      double avrGr = this->getGroups().at(i)->calculateAverageMark();
      out << title << " -- " << spec << std::endl;
      out << "Average mark of the group: " << avrGr << std::endl;
      out << "Head: " << this->getGroups().at(i)->getHead()->
          getFio() << std::endl;
      out << "{" << std::endl;
      for (int j = 0; j < this->getGroups().at(i)->getStudents().size(); ++j) {
        std::string id = this->getGroups().at(i)->getStudents().at(j)->getId();
        std::string name = this->getGroups().at(i)->getStudents().at(j)->
            getFio();
        double avr = this->getGroups().at(i)->getStudents().at(j)->
            calculateAverageMark();
        out << id << " --- " << name << " --- average: " << avr << std::endl;
      }
      out << "}" << std::endl;
    }
  }
  out.close();
}




