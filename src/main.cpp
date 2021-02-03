// Copyright 2021 Kuznetsov Mikhail
#include "fstream"
#include "iostream"
#include "Group.h"
#include "Student.h"
#include "Deanary.h"
int main() {
  Deanary deanary("../stats/Groups.txt");
  deanary.hireStudents("../stats/Students.txt");
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  deanary.getStatistics("../stats/Stat.txt");
  deanary.fireStudents();
  deanary.saveStaff("../stats/Groups.txt", "../stats/Students.txt");
  return 0;
}
