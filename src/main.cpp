// Copyright 2021 Bugrov

#include <iostream>

#include "Deanary.h"
#include "Group.h"
#include "Student.h"

int main() {
  Deanary HSE;
  Student student_2(98, "Вася Пупкин");
  Student student_3(97, "неВася неПупкин");
  Student student_1(99, "Святослав Игоревич");

  student_1.add_mark(1);
  student_1.add_mark(2);
  student_1.add_mark(3);
  std::cout << student_1.average_mark() << '\n';

  Group Fil("ПМИ1", "прикл. мат. и инф.");
  Fil.add_student(& student_1);
  Fil.choose_headman();
  std::cout << Fil.average_mark() << '\n';

  HSE.add_group(Fil);
  std::cout << HSE.get_statistic_groups("прикл. мат. и инф.") << '\n';

  HSE.print();

  return 0;
}
