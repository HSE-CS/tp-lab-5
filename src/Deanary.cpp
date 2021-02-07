// Copyright 2020 Dumarevskaya
#include "Deanary.h"

void Deanary::createGroup() {
  for (auto i : groups) {
    std::string name = i->title + ".txt";
    std::ifstream file(name);
    std::string student, id, fio;
    while (getline(file, student)) {
      id = student.substr(0, student.find(' '));
      fio = student.substr(student.find(' ') + 1);
      i->addStudent(new Student (id, fio));
    }
  }
}

void Deanary::addGroup(Group* group) {
  groups.push_back(group);
}

void Deanary::hireStudents(Student* student, std::string group) {
  for (auto i : groups) {
    if (i->title == group) {
      i->addStudent(student);
      return;
    }
  }
  std::cout << "there isn't such group" << std::endl;
}

void Deanary::addMarksToAll(us mark, std::string name_group) {
  for (auto i : groups) {
    if (i->title == name_group) {
      for (auto j : i->students) {
        j->addmark(mark);
      }
      return;
    }
  }
}

void Deanary::moveStudents(std::string student, std::string group_from, std::string group_to) {
  for (auto i : groups) {
    if (i->title == group_from) {
      for (auto j : groups) {
        if (j->title == group_to) {
          j->addStudent(i->getStudent(student));
        }
      }
      i->removeStudent(i->getStudent(student));
    }
  }
}


void Deanary::getStatistic() {
  for (auto i : groups) {
    std::cout << i->title << ": " << i->getAveragemark() << std::endl;
  }
}

void Deanary::saveStaff() {
  std::ofstream hse("hse.txt");
    if (hse.is_open()) {
        for (auto i : groups) {
            hse << "Title: " << i->title << "  Spec: "
                << i->spec << std::endl;
            hse << "Average mark: "
                << i->getAveragemark() << std::endl;
            hse << "Head: " << i->head->fio << std::endl;
            hse << "Students:" << std::endl;
            for (auto j : i->students) {
              hse << j->id << " " << j->fio
                << "Average mark: " << j->getAveragemark()
                << std::endl;
            }
            hse << std::endl << std::endl;
        }
    }
    hse.close();
}

void Deanary::initHeads(std::string group, std::string student) {
  for (auto i : groups) {
    if (i->title == group) {
      i->chooseHead(i->getStudent(student));
      return;
    }
  }
}

void Deanary::fireStudents(std::string student, std::string group) {
  for (auto i : groups) {
    if (i->title == group) {
      i->removeStudent(i->getStudent(student));
    }
    return;
  }
}

Student* Deanary::getStudent(std::string name, std::string group) {
  for (auto i : groups) {
    if (i->title == group) {
      for (auto j : i->students) {
        if (j->fio == name || j->id == name) {
          return j;
        }
      }
      std::cout << "there is no such student in the " << i->title << " group" << std::endl;
      return new Student("error", "error");
    }
  }
}

Group* Deanary::getGroup(std::string group) {
  for (auto i : groups) {
    if (i->title == group) {
      return i;
    }
  }
}
