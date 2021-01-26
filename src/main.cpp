// Copyright 2020 Longa Bonga
#include <cstring>
#include <iostream>
#include <string>

#include "Student.h"

int main() {
  Student student("Ivan Dobryaev");
  std::cout << student.getAveragemark() << '\n';
  std::cout << student.isHeadOfGroup() << '\n';
}
