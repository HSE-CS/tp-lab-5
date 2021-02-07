// Copyright 2021 ArinaMonicheva

#include <iostream>
#include "Deanary.h"

int main() {
  time_t* n = NULL;
  srand(time(n));
  Deanery newDeanery;
  Group* newGroup = new Group("19PI-2");

  std::ifstream groupsFile("groups.txt");
  newDeanery.createGroups(groupsFile);
  groupsFile.close();

  std::ifstream studentsFile("students.txt");
  newDeanery.hireStudents(studentsFile);
  studentsFile.close();

  newDeanery.addMarksToAll();

  std::vector<Group*> allGroups = newDeanery.getGroups();
  newDeanery.printToConsole(*(allGroups[0]));
  // changing the value of the first item in vector
  allGroups[0] = newGroup;
  // printed result woulb be different
  newDeanery.printToConsole(*(allGroups[0]));
  allGroups = newDeanery.getGroups();
  // but the original class object has not changed
  newDeanery.printToConsole(*(allGroups[0]));

  stats stats1 = newDeanery.getStatistics();
  newDeanery.printToConsole(stats1);

  Student* newStudent = new Student(123456, "Monicheva Arina Aleksandrovna");
  for (int i = 0; i < 8; i++) {
    newStudent->addMark(6 + rand_r(n) % 5);
  }

  std::cout << newStudent->getAverageMark() << std::endl;

  allGroups[0]->addStudent(*newStudent);
  stats1 = newDeanery.getStatistics();
  newDeanery.printToConsole(stats1);

  newDeanery.initHeads(*(allGroups[0]));
  newDeanery.printToConsole(*(allGroups[0]));
  std::cout << newStudent->isHeadOfGroup() << std::endl;

  newDeanery.printToConsole(allGroups[0]->getStudent(123456));
  newDeanery.printToConsole(
  allGroups[0]->getStudent("Monicheva Arina Aleksandrovna"));
  std::cout << "Num in list: " << allGroups[0]->containsStudent(123456)
  << "Num in list: " <<
  allGroups[0]->containsStudent("Monicheva Arina Aleksandrovna") << std::endl;

  newDeanery.moveStudents(*newStudent, *newGroup);
  newDeanery.printToConsole(*newStudent);

  stats1 = newDeanery.getStatistics();
  newDeanery.printToConsole(stats1);

  newDeanery.addNewGroup(newGroup);
  stats1 = newDeanery.getStatistics();
  newDeanery.printToConsole(stats1);

  newDeanery.fireStudents();
  allGroups = newDeanery.getGroups();
  for (int i = 0; i < allGroups.size(); i++) {
    newDeanery.printToConsole(*(allGroups[i]));
  }

  std::ofstream resafeSt("restudents.txt");
  std::ofstream resafeGr("regroups.txt");
  newDeanery.safeStaff(resafeGr, resafeSt);
  resafeGr.close();
  resafeSt.close();

  delete newGroup;
  delete newStudent;

  return 0;
}
