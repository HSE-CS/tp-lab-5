// Copyright 2021 Kuznetsov Mikhail
#include "fstream"
#include "iostream"
#include "Group.h"
#include "Student.h"
#include "Deanary.h"
int main() {
  Deanary deanary;
  deanary.createGroups("../stats/Groups.txt");
  deanary.hireStudents("../stats/Students.txt");
  deanary.initHeads();
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  deanary.printData();
  deanary.fireStudents();
  deanary.printData();
  deanary.getStatistics("../stats/Stat.txt");
  deanary.saveStaff("../stats/Groups.txt", "../stats/Students.txt");
  return 0;
}
