#include "Deanary.h"
#include "Student.h"
#include "Group.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring> 

int main(int argc, char* argv[]) {
	Deanary dec;
	dec.createGroups("Groups.txt");
	dec.hireStudents("Students.txt");
	dec.addMarksToAll();
	dec.getStatistics();
	dec.saveStaff("Groups.txt", "Students.txt");
}
