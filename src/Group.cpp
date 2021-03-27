// Copyright 2021 KarMashanova
#include "Group.h"
#include "Student.h"
#include <iostream>
#include <vector>

void Group::addStudent(Student *student) { students->push_back(student); }
void chouseHead() { 
	int initalHeadId = -1;
  if (isEmpty) {

  }
}

bool Group::isEmpty() { return this->students->empty(); }
