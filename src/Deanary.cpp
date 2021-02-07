//  Copyright 2020 GHA created by Klykov Anton

#include "Deanary.h"
#include <cstdlib>
#include <ctime>

void Deanary::createGroups() {
  CreateGroup_F create_group;
  create_group.readFile();
  size_t size{create_group.getTitle().size()};
  for (size_t i = 0; i < size; ++i) {
    groups.push_back(create_group.parseGroup());
  }
}
void Deanary::hireStudent() {
  CreateStudent_F create_student;
  create_student.readFile();
  size_t size{create_student.getFio().size()};
  size_t amountGroups{groups.size()};
  srand(static_cast<unsigned int>(time(nullptr)));
  size_t rand_amount{0};
  unsigned int coef_rand{0};
  for (size_t i = 0; i < amountGroups; ++i) {
    for (size_t k = 0; k < groups.at(i)->title.size(); ++k) {
      coef_rand += groups.at(i)->title.at(k);
    }
    rand_amount = (((rand() * coef_rand) * (25 - 16 + 1)) / RAND_MAX) + 15;  // 55 человек
    for (size_t j = 0; j < ((i == amountGroups - 1) ? size : rand_amount); ++j) {
      groups.at(i)->addStudent(create_student.parseStudent());
    }
    size -= rand_amount;
  }
}
void Deanary::initHeaders() {
  for (size_t i = 0; i < groups.size(); ++i) {
    groups.at(i)->chooseHeader();
  }
}
void Deanary::fireStudent(int _id) {
  for (size_t i = 0; i < groups.size(); ++i) {
    if(groups.at(i)->delStudent(groups.at(i)->getStudent(_id))) {
      return;
    }
  }
}
void Deanary::moveStudent(int _id, int number_group) {
  Student* removingStudent;
  for (size_t i = 0; i < groups.size(); ++i) {
    removingStudent = groups.at(i)->removeStudent(groups.at(i)->getStudent(_id));
    if(removingStudent) {
      if (removingStudent->group != groups.at(number_group)) {
        groups.at(number_group)->addStudent(removingStudent);
        return;
      } else {
        std::cout << "Student is there already!" << std::endl;
        return;
      }
    }
  }
  std::cout << "He leave the university!" << std::endl;
}
void Deanary::addMarksToAll() {
  static int iteration{0};
  for (size_t i = 0; i < groups.size(); ++i) {
    for (size_t j = 0; j < groups.at(i)->students.size(); ++j) {
      groups.at(i)->students.at(j)->addMark(iteration);
    }
  }
  iteration++;
}
void Deanary::getStatistics() {
  for (size_t i = 0; i < groups.size(); ++i) {
    std::cout << groups.at(i)->title << ": " << groups.at(i)->getAverageMark() << std::endl;
    for (size_t j = 0; j < groups.at(i)->students.size(); ++j) {
      std::cout << "  " << groups.at(i)->students.at(j)->FinSenThn << ": " << groups.at(i)->students.at(j)->getAverageMark() << std::endl;
    }
  }
}
void Deanary::fireBadStudents() {
  for (size_t i = 0; i < groups.size(); ++i) {
    for (size_t j = 0; j < groups.at(i)->students.size(); ++j) {
      if (groups.at(i)->students.at(j)->getAverageMark() <= 2) {
        fireStudent(groups.at(i)->students.at(j)->id);
      }
    }
  }
}
int Deanary::getAmountGroup() {
  return groups.size();
}
std::string Deanary::getTitleGroup(int _num) {
  return groups.at(_num)->title;
}
int Deanary::getAmountStudents(int _num) {
  return groups.at(_num)->students.size();
}
Group* Deanary::getGroup(int _num) {
  return groups.at(_num);
}

