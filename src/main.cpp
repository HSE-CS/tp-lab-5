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
  my_deanary.fireStudent(3.0);
  my_deanary.getStatistics();
  my_deanary.saveStuff("/Users/sanduser/Documents/Projects/Xcode/cpp_exmp/Saves/");
}
