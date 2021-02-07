// Copyright 2021 Egor Buzanov

#include "../include/Deanary.h"

int main() {
  Deanary dean;
  dean.createGroups("C:/projects/GitHub/tp-lab-5/Groups.txt");
  dean.hireStudents("C:/projects/GitHub/tp-lab-5/Names.txt");
  dean.initHeads();
  dean.addMarksToAll();
  dean.MoveStudents(50, "FundamentalMathematics");
  dean.getStatistics("C:/projects/GitHub/tp-lab-5/Statistics.txt");
  dean.fireStudents();
  dean.saveStaff("C:/projects/GitHub/tp-lab-5/Result_groups.txt",
                 "C:/projects/GitHub/tp-lab-5/Result_students.txt");
  return 0;
}
