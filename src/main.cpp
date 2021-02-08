// Copyright Nikita Demashow 2021
#include"Student.h"
#include"Group.h"
#include"Deanary.h"

int main() {
  setlocale(LC_ALL, "Russian");
  Deanary HSENN;
  HSENN.createGroups("groups.txt");
  HSENN.hireStudents("students.txt");
  for (auto i{0}; i < 10; ++i) {
    HSENN.addMarksToAll();
  }
  HSENN.getStatistics();
  HSENN.initHeads();
  HSENN.saveStaff("statistic.txt");
}
