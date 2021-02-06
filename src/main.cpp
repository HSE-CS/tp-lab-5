// Copyright 2021 Dev-will-work
#include <iostream>
#include <string>
#include "Deanary.h"
#include "Group.h"
#include "Student.h"

int main() {
  Deanary d;
  // d.getLastState();
  // d.fireStudents(1);
  // d.moveStudents("3", "4");
  d.createGroups(4);
  d.createGroups(2);
  d.hireStudents(10);
  d.addMarksToAll(6);
  d.initHeads();
  d.saveStaff();
  d.getStatistics();
}
