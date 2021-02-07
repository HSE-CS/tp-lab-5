// Copyright 2021 Galex
#include <iostream>
#include "../include/Deanary.h"

int main() {
  Deanary SE("Software Engineering");
  SE.createGroups();
  SE.createGroup("19SE5");
  SE.hireStudents();
  SE.addMarks2All(10);
  SE.fireStudent(1);
  SE.moveStudent(SE.getGroup(1)
                     ->getStudentByIndex(0), SE.getGroup(1),
                 SE.getGroup(2));
  SE.hireStudent("Александров Александр Александрович", 4);
  std::cout << SE.getAverage();
  // SE.saveState();
}
