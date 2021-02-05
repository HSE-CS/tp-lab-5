// Copyright (c) 2021 Alexey Klimov
//
// Created by Alexey on 29.01.2021.
//
#include <iostream>
#include "Deanary.h"
#include "Student.h"
#include "Group.h"

int main() {
  Deanary d;

  d.from_file("students.txt");

  d.add_marks_to_all(2);
  d.add_marks_to_all(5);
  d.add_marks_to_all(5);

  std::cout << d.get_statistics();

  return 0;
}
