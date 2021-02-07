// Copyright 2021 Pavlova D.
#include <iostream>
#include "../include/Deanary.h"

int main() {
  Deanary den;
  den.createGroups();
  den.hireStudents();
  den.initHeads();

  den.addMarksToAll(10);
  den.getStatistics();

  std::string title = "transformers";
  den.moveStudents(7, title);
  den.fireStudents();
  den.saveStaff();
}
