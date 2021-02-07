// Copyright 2021 Smirnov Grigory
#include "..\include\Deanery.h"

Group* groupReader(std::string path) {
  std::ifstream file(path);
  std::string title;
  std::string spec;
  std::getline(file, title);
  std::getline(file, spec);
  Group* result = new Group(title, spec);
  std::random_device seed;
  std::string fio;
  std::getline(file, fio);
  while (fio != "EOF") {
    Student* newbie = new Student((seed()%100000), fio);
    result->addStudent(newbie);
    std::getline(file, fio);
  }
  return result;
}

int main() {
  Group* eco1 = groupReader("..\\..\\test\\groups_input\\eco1.txt");
  Group* eco2 = groupReader("..\\..\\test\\groups_input\\eco2.txt");
  Group* prog1 = groupReader("..\\..\\test\\groups_input\\prog1.txt");
  Group* prog2 = groupReader("..\\..\\test\\groups_input\\prog2.txt");
  std::vector<Group*> groups(4);
  groups[0] = eco1;
  groups[1] = eco2;
  groups[2] = prog1;
  groups[3] = prog2;
  Deanery D(groups);

  D.addRandomMarks(10);
  D.initHeads();
  //D.academicPerformance();
  D.fireWeakStudents();
  D.printInfo();
  D.saveStaff("..\\..\\test\\archive\\archive_deanery.txt");
}
