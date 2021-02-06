// Copyright 2021 mkhorosh
#include <iostream>
#include "Deanary.h"
#include "Parser.h"

int main() {
  std::vector<std::string> fios = {};
  std::vector<std::string> ids = {};
  std::vector<std::string> titles = {};
  std::vector<std::string> specs = {};
  parse_groups(&titles, &specs,
               "C:\\Users\\Marina\\CLionProjects\\tp-lab-5\\data\\groups.txt");
  std::string stfile = "C:\\Users\\Marina\\CLionProjects\\tp-lab-5\\data\\students.txt";
  parse_students(&fios, &ids, stfile);
  Deanary mse;
  mse.createGroups(titles, specs);
  mse.hireStudents(fios, ids);
  mse.addMarksToAll();
  mse.getStatistics();
  mse.initHeads();
  mse.printData();
  mse.moveStudent(ids[0], titles[0]);
  mse.printData();
  mse.fireStudents();
  mse.printData();
  mse.saveStaff("C:\\Users\\Marina\\CLionProjects\\tp-lab-5\\data\\staff.txt");
  return 0;
}
