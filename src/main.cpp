//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include <stdio.h>
#include <iostream>
#include <string>
#include <thread>
#include <fstream>
#include <sstream>
#include <vector>

#include "Deanary.h"



int main() {
  Deanary my_deanary;
  my_deanary.hireStudents("/Users/sanduser/Documents/Projects/Xcode/cpp_exmp/studentsData.txt");
  my_deanary.createGroups("/Users/sanduser/Documents/Projects/Xcode/cpp_exmp/groupsData.txt");
  my_deanary.initHeads();
  my_deanary.addMarksToAll();
  my_deanary.getStatistics();
  
  Group test_group = my_deanary.getGroup(-1, "Group1");
  std::cout << "Group1 info (read only): " << std::endl;
  std::cout << "spec: " << test_group.getSpec() << std::endl;
  std::cout << "size: "  << test_group.getStudentsNum() << std::endl;
  std::cout << "head: " << test_group.getHead().getFio() << std::endl << std::endl;
  Student test_student = test_group.getStudent(0);
  std::cout << "Student (first in Group1) info (read only): " << std::endl;
  std::cout << "name: " << test_student.getFio() << std::endl;
  std::cout << "group: " << test_student.getGroup().getTitle() << std::endl << std::endl;
  
  std::cout << "FIRING!" << std::endl;
  my_deanary.fireStudent(3.0);
  my_deanary.getStatistics();
  my_deanary.saveStuff("/Users/sanduser/Documents/Projects/Xcode/cpp_exmp/Saves/");
}
