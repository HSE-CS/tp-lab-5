// Copyright 2021 Smirnov Grigory
#include "..\include\Deanery.h"
int main() {
  std::string iam = "Smirnov Grigory Andreevich";
  Student test = Student(15, iam);
  test.addMark(1);
  test.addMark(500);
  test.addMark(2);
  std::cout << test.getAverageMark();
}
