// Copyright 2021 Nikita Naumov
#include "Student.h"
#include "Group.h"

int main() {
  Group group((std::string)"19PMI");
  Student test1(0, (std::string) "Name Surname");
  test1.getInfo();  //work
  test1.printMarks();  //work
  for (size_t i = 0; i < 5; ++i) {
    test1.addMarkToStudent(rand()%11);  //work
  }
  test1.printMarks();  //work
  std::cout << test1.getAverageMark() << std::endl;  //work
  std::cout << std::endl;
  test1.addToGroup(&group);
  test1.getInfo();

  return 0;
}