// Copyright 2021 Schenikova

#include "Deanary.h"

void Deanary::initHeads() {
  for (auto group : groups) {
    group->chooseHead();
  }
}

Deanary::Deanary(std::string filename) {
  createGroups(filename);
}

void Deanary::createGroups(std::string filename) {
  std::ifstream fin(filename);
  std::string spec;
  std::string title;
  while (fin >> spec >> title) {
    // std::cout << spec << std::endl;
    // std::cout << title << std::endl;
    Group* gr = new Group(title, spec);
    groups.push_back(gr);
  }
  fin.close();

}

void Deanary::hireStudents(std::string filename) {
  std::ifstream fin(filename);
  std::string line;
  while (getline(fin, line)) {
    Student* s = new Student(id++, line);
    // unsigned seed = std::chrono::system_clock::
    // now().time_since_epoch().count();
    static std::default_random_engine generator(time(0));
    // static std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0, groups.size());
    int ind = distribution(generator);
    // std::cout << ind << std::endl;
    groups[ind]->addStudent(s);
    s->addToGroup(groups[ind]);
  }
  fin.close();
}

void Deanary::addMarksToAll() {
  std::srand(time(0));
  for (auto g : groups) {
    for (auto s : g->containsStudent()) {
      int mark = std::rand() % 11;
      s->addMark(mark);
    }
  }
}

void Deanary::getStatistics(std::string filename) {
  std::ofstream fout(filename);
  for (auto g : groups) {
    fout << g->getTitle() << " Average mark: " << g->getAveragemark() << "\n";
    for (auto student : g->containsStudent()) {
      fout << student->getId() << " " << student->getfio() << ": "
      << student->getAveragemark() << "\n";
      // std::cout << student->getId() << std::endl;
    }
    fout << "\n";
  }
  std::cout << "success" << std::endl;
  fout.close();
}

void Deanary::moveStudents(int id, std::string title) {
  Student* student = nullptr;
  Group* group = nullptr;
  for (auto g : groups) {
    student = g->getStudentById(id);
    if (student != nullptr) {
      break;
    }
  }
  for (auto g : groups) {
    if (g->getTitle() == title) {
      group = g;
      break;
    }
  }
  if (student!= nullptr && group!= nullptr) {
    student->getGroup()->removeStudent(student);
    group->addStudent(student);
    student->addToGroup(group);
  }
}

void Deanary::saveStaff(std::string fileGroups, std::string fileStudents) {
  std::ofstream fgroup(fileGroups);
  std::ofstream fstudent(fileStudents);
  for (auto group : groups) {
    fgroup << group->getSpec() << " " << group->getTitle() << "\n";
    for (auto student : group->containsStudent()) {
      fstudent << student->getfio() << "\n";
    }
  }
  fgroup.close();
  fstudent.close();
}

void Deanary::fireStudents() {
  for (auto group : groups) {
    for (auto student : group->containsStudent()) {
      float mark = student->getAveragemark();
      if (mark < 3.5) group->removeStudent(student);
    }
  }
}


int Deanary::randomId() {
  std::srand(time(0));
  int id = 10000000 + std::rand() % 90000000;
  // std::cout << id << std::endl;
  return id;
}

void Deanary::printAllInfo() {
  std::cout << "Information about groups\n" << std::endl;
  std::cout << "-------------------------------------------\n" << std::endl;
  for (auto g : groups) {
    g->printAllAboutGroup();
    std::cout << "\n";
  }
  std::cout << "Information about students\n" << std::endl;
  std::cout << "-------------------------------------------\n" << std::endl;
  for (auto g : groups) {
    for (auto s : g->containsStudent()) {
      s->printAllAboutStudent();
      std::cout << "\n\n";
    }
  }
}