// Copyright 2020 me
#include <iostream>
#include "../include/Deanary.h"


int main() {
  Deanary dean;
  dean.createGroups("../tp-lab-5/src/groups.json");
  dean.hireStudents("../tp-lab-5/src/data.json", 100);
  dean.initHeads();
  dean.addMarksToAll();
  dean.addMarksToAll();
  dean.addMarksToAll();
  dean.getStatistics();
  dean.saveStaff();
  dean.moveStudents(20, "PI");
  dean.saveStaff("save1.txt");
  dean.fireStudents(84);
  dean.saveStaff("save2.txt");
}
