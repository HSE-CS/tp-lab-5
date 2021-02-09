// Copyright 2021 Shirokov Alexander

#include "Student.h"
#include "Group.h"
#include "Deanary.h"

void Deanary::createGroups(const std::string& path) {
  std::ifstream file(path);
  std::string TITLE;
  std::string SPEC;
  while (file >> TITLE) {
    std::getline(file, SPEC);
    Group* g = new Group(TITLE, SPEC);
    groups.push_back(g);
  }
  file.close();
}

void Deanary::hireStudents(const std::string& path) {
  std::ifstream file(path);
  std::string name;
  int id;
  std::vector <Student*> students;

  while (file >> id) {
    std::getline(file, name);
    Student* s = new Student(id, name);
    students.push_back(s);
    if (groups.size() > 0) {
      int index = 0;
      int min = 37;
      for (int i = 0; i < groups.size(); i++) {
        if (groups[i]->students.size() < min) {
          min = groups[i]->students.size();
          index = i;
        }
      }
      groups[index]->addStudent(s);
    }
  }
  file.close();
}

void Deanary::addMarksToAll() {
  std::srand(time(0));
  for (Group* g : groups) {
    for (Student* s : g->students) {
      s->addmark(std::rand() % 10 + 1);
    }
  }
}

void Deanary::getStatistics() {
  for (Group* g : groups) {
    std::cout << g->title << ", " << g->spec << '\n';
    std::cout << "Head: " << g->head->fio << '\n';
    std::cout << "Average mark of group: " << g->getAveragemark() << '\n';
    for (Student* s : g->students) {
      std::cout << "ID: " << s->getId() << ", name:" << s->getName() << ", ";
      std::cout << "average mark: " << s->getAveragemark() << '\n';
    }
    std::cout << '\n';
  }
}

void Deanary::moveStudents(Group* from, Group* to, std::vector<Student*> students) {
  for (Student* st : students) {
    from->removeStudent(st);
    to->addStudent(st);
  }
}

void Deanary::saveStaff(const std::string& studentsPath, const std::string& groupsPath) {
  std::ofstream file1(studentsPath);

  for (auto gr : groups) {
    for (auto st : gr->students) {
      file1 << st->getId() << " " << st->getName() << '\n';
    }
  }
  file1.close();

  std::ofstream file2(groupsPath);

  for (auto gr : groups) {
    file2 << gr->title << " " << gr->spec << ":\n";
    for (auto st : gr->students) {
      file2 << st->getId() << " " << st->getName() << '\n';
    }
  }
  file2.close();
}

void Deanary::initHeads() {
  std::srand(time(0));
  for (auto g : groups) {
    g->chooseHead(g->students[std::rand() % g->students.size()]);
  }
}

void Deanary::fireStudents(std::vector<Student*> students) {
  for (Group* g : groups) {
    for (Student* st : students) {
      g->removeStudent(st);
    }
  }
}

std::vector<Group*> Deanary::getGroups() {
  return groups;
}
