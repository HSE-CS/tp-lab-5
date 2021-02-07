// Copyright 2021 Egor Buzanov

#include "Deanary.h"

int main() {
  Deanary dean;
  dean.createGroups("Groups.txt");
  dean.hireStudents("Names.txt");
  dean.initHeads();
  dean.addMarksToAll();
  dean.MoveStudents(50, "FundamentalMathematics");
  dean.getStatistics("Statistics.txt");
  dean.fireStudents();
  dean.saveStaff("Result_groups.txt", "Result_students.txt");
  return 0;
}
