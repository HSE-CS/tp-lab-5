//  Copyright 2020 GHA created by Klykov Anton

#include "Deanary.h"
#include "Student.h"
#include "Group.h"
#include <iostream>

int main() {
  Deanary deanary;
  deanary.createGroups();
  deanary.hireStudent();
  deanary.initHeaders();
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  deanary.getStatistics();
  /*deanary.fireBadStudents();
  deanary.getStatistics();
  deanary.moveStudent(0, 2);
  deanary.moveStudent(46, 0);
  deanary.moveStudent(21, 0);
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  deanary.getStatistics();
  deanary.fireBadStudents();
  deanary.getStatistics();
  deanary.fireStudent(0);
  deanary.moveStudent(0, 2);*/
  return 0;
}
