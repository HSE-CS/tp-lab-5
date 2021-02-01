// Copyright 2020 GHA Test Team
#include <iostream>
#include "Deanary.h"


int main() {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "students.txt", "groups.txt", false);
  deanary->printDeanary(true);
  deanary->printStatistics();
  deanary->fireStudents();
  deanary->printDeanary(true);
  deanary->printStatistics();
  // deanary->moveStudents("Кулакова Ярослава Алексеевна", "Группа2");
  // deanary->moveStudents("Убыша Оксана Захаровна", "Группа1");
  // deanary->printDeanary(true);
  deanary->saveStaff("new_students.txt", "new_groups.txt");
  // DataReader* reader = new DataReader("students.txt", "groups.txt");
  // std::vector<std::string> groups = reader->getGroups();
  // std::vector<std::string> students = reader->getStudents();
  // for (unsigned i = 0; i < groups.size(); i++)
  //   std::cout << groups.at(i) << std::endl;
  // for (unsigned i = 0; i < students.size(); i++)
  //   std::cout << students.at(i) << std::endl;
  return 0;
}
