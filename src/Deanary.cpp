// Copyright Nikita Demashow 2021
#include"Deanary.h"
#include"Student.h"
#include"Group.h"
#include<iomanip>

void Deanary::createGroups(const std::string& dir) {
  std::ifstream file(dir);
  if (file) {
    std::string line;
    while (std::getline(file, line)) {
      std::string title, spec;
      bool wasSpace{false};
      for (auto el : line) {
        if (el == ' ') {
          wasSpace = true;
        } else if (wasSpace) {
          spec += el;
        } else {
          title += el;
        }
      }
      Group* newGr = new Group(title, spec);
      groups.push_back(newGr);
    }
  } else {
    std::cout << "There is not file" << std::endl;
  }
}
void Deanary::hireStudents(const std::string& dir) {
  std::ifstream file(dir);
  std::string line;
  while (std::getline(file, line)) {
    std::string fio, spec;
    bool wasSpace{false};
    int16_t cnt{0};
    for (auto el : line) {
      if (el == ' ') {
        if (cnt == 2) {
          wasSpace = true;
        } else {
          fio += ' ';
          cnt++;
        }
      } else if (wasSpace) {
        spec += el;
      } else {
        fio += el;
      }
    }
    for (auto group : groups) {
      if (group->spec == spec && !group->isFull()) {
        Student* newSt = new Student(fio);
        newSt->addToGroup(group);
        group->students.push_back(newSt);
        break;
      }
    }
  }
}
void Deanary::addMarksToAll() {
  for (auto group : groups) {
    for (auto student : group->students) {
      int mark{rand() % 11};
      if (student->iq >= 110 && mark < 6 || student->iq < 110 && mark >= 6) {
        mark = rand() % 11;
      }
      student->addMark(mark);
    }
  }
}
void Deanary::getStatistics() {
  std::cout << std::setiosflags(std::ios::left) << std::setw(3) << "ID"
            << std::setw(35) << "Name" << std::setw(6) << "AvMark" << std::endl;
  for (auto group : groups) {
    for (auto student : group->students) {
      std::cout << std::setw(3) << student->id << std::setw(35) << student->fio
                << std::setw(6) << student->getAverageMark() << std::endl;
    }
  }
  std::cout << std::setiosflags(std::ios::left) << std::setw(6) << "Title"
            << std::setw(10) << "Spec" << std::setw(6) << "AvMark" << std::endl;
  for (auto group : groups) {
    if (!group->isEmpty()) {
      std::cout << std::setiosflags(std::ios::left) << std::setw(6)
                << group->title << std::setw(10) << group->spec << std::setw(6)
                << group->getAverageMark() << std::endl;
    }
  }
}
void Deanary::initHeads() {
  for (auto group : groups) {
    if (!group->isEmpty()) {
      group->choseHead();
      std::cout << group->title << " - " << group->head->fio << std::endl;
    }
  }
}

void Deanary::fireStudent(Student* st) {
  for (auto group : groups) {
    for (size_t i{0}; i < group->students.size(); ++i) {
      if (group->students[i]->id == st->id) {
        group->students.erase(group->students.begin() + i);
      }
    }
  }
}

void Deanary::moveStudets(const unsigned int id, const std::string title) {
  Group* gr{NULL};
  Student* st{NULL};
  for (auto group : groups) {
    if (group->title == title) {
      gr = group;
      if (group->isFull()) {
        std::cout << "Group " << title << " id full" << std::endl;
        break;
      }
    }
    if (!group->isEmpty() && !st) {
      st = group->getStudentById(id);
    }
    if (gr && st) {
      break;
    }
  }
  if (!gr) {
    std::cout << "There is not group" << std::endl;
  } else if (!gr->isFull()) {
    if (!st) {
      std::cout << "There is not student" << std::endl;
    } else {
      st->group->removeStudent(st->fio);
      st->addToGroup(gr);
      gr->addStudent(st);
    }
  }
 }
void Deanary::saveStaff(const std::string dir) {
    std::ofstream file(dir);
  for (auto group : this->groups) {
      for (auto student : group->students) {
      file << student->getFio() << " Group: " << student->group->title
           << " Marks: " << student->getMarks() << std::endl;
      }
  }
}
void Deanary::addGroup(Group* gr) { groups.push_back(gr); }
int Deanary::getCntGroups() { return groups.size(); }
