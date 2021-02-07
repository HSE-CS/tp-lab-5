// Copyright 2021 Artem Danyaev
#include "Deanary.h"
#include <iostream>
int main() {

  Deanary d;
  d.createGroupsFromFile("groups.txt");
  d.hireStudentsFromFile("students.txt");
  d.addMarksToAll();
  d.initHeads();
  d.getStatistics("stats.txt");
  d.saveStuff("stuff.txt");

  return 0;
}