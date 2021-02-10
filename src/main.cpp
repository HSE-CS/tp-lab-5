// Copyright 2021 Tatsenko Alexey
#include <iostream>
#include "Group.h"
#include "Student.h"

int main() {
  Student I("123", "Tatsenko Alexey");
  Group HSE("HSE", "SE");
  HSE.AddStudent(&I);
  std::cout << HSE.GetLastStudents() << std::endl;
  std::cout << HSE.GetSpec();
  std::cout << HSE.GetTitle();
  Student Andrey("1243", "Andrey Bakur");
  HSE.AddStudent(&Andrey);
  HSE.RemoveStudent(&Andrey);
  std::cout << HSE.GetLastStudents();
}
