// Copyright 2021 Kuznetsov Mikhail
#include "Deanary.h"

Deanary::Deanary(std::string filename) {
  // std::ifstream fin(filename);
  curr_id = 1;
  createGroups(filename);
  initHeads();
  // fin.close();
}
/*
Deanary::~Deanary(){
   for(auto g: groups)
    delete group;
}
*/

void Deanary::createGroups(std::string filename) {
  std::ifstream fin(filename);
  std::string input;
  std::string spec;
  std::string title;
  while (getline(fin, input)) {
    int pos = input.find(':');
    spec = input.substr(0, pos);
    title = input.substr(pos + 1, input.size() - pos - 1);
    std::cout << spec << "\n";
    Group* g = new Group(title, spec);
    // std::cout << groups.size() << " " << g->getSpec() << "\n";
    // groups.push_back(new Group(spec, title));
    groups.push_back(g);
  }
  fin.close();
}

void Deanary::hireStudents(std::string filename) {
  std::ifstream fin(filename);
  std::string input;
  while (getline(fin, input)) {
    Student* s = new Student(curr_id++, input);
    std::mt19937 gen(time(0));
    std::uniform_int_distribution<> uid(0, groups.size() - 1);
    int ind = uid(gen);
    groups[ind]->addStudent(s);
    s->addToGroup(groups[ind]);
  }
  fin.close();
}
void Deanary::addMarksToAll() {
  for (auto g : groups) {
    for (auto s : g->containsStudents()) {
      std::mt19937 gen(time(0));
      std::uniform_int_distribution<> uid(0, 100);
      int mark = uid(gen);
      s->addMark(mark);
    }
  }
}
void Deanary::getStatistics(std::string filename) {
  std::ofstream fout(filename);
  fout.precision(2);
  fout.setf(std::ios::fixed);
  for (auto g : groups) {
    fout << g->getSpec() << "\n" << g->getTitle() << "\n";
    fout << "Average mark: " << g->getAveragemark() << "\n";
    auto list_group = g->containsStudents();
    for (auto s : list_group) {
      fout << s->getId() << " " << s->getFio() << " "
      << s->getAveragemark() << "\n";
    }
  }
}
void Deanary::moveStudents(unsigned int id, std::string title) {
  Student* s = getStudent(id);
  Group* g = getGroup(title);
  s->getGroup()->removeStudent(s);
  g->addStudent(s);
  s->addToGroup(g);
}
void Deanary::saveStaff(std::string filename_groups,
                        std::string filename_students) {
  std::ofstream fgr(filename_groups);
  std::ofstream fst(filename_students);
  for (auto g : groups) {
    auto list_group = g->containsStudents();
    fgr << g->getSpec() << ":" << g->getTitle() << "\n";
    for (auto s : list_group) {
      fst << s->getFio() << "\n";
    }
  }
  fgr.close();
  fst.close();
}

void Deanary::initHeads() {
  for (auto g : groups) {
    g->chooseHead();
  }
}

void Deanary::fireStudents() {
  for (auto g : groups) {
    auto list_group = g->containsStudents();
    for (auto s : list_group) {
      float mark = s->getAveragemark();
      if (mark < 35.0 && fabs(mark - 35.0) > 1e-6) {
        g->removeStudent(s);
      }
    }
  }
}

Group* Deanary::getGroup (std::string title) {
    for (auto g : groups) {
        if (g->getTitle() == title) {
            return g;
        }
    }
    return nullptr;
}

Student* Deanary::getStudent(unsigned int id) {
  Student* find = nullptr;
  for (auto g : groups) {
    find = g->getStudent(id);
    if (find != nullptr)
      return find;
  }
  return nullptr;
}

