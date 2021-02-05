// Copyright 2020 Konina Tatiana
#include <iostream>
#include "Deanary.h"
#include "Student.h"
#include "Group.h"

int main() {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  test->initHeads();
  test->fireStudents();
  Group* gr = test->getGroups()[0];
  std::cout << gr->getGroupSize();
  return 0;
}

