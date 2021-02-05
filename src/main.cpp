#include "Deanary.h"
#include "Student.h"
#include "Group.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <locale.h>  
#include <cstring> 

int main(int argc, char* argv[]) {
	std::ofstream fout;
	fout.open("Groupmarks.txt");
	fout << "HEY" << "\n";
	Deanary dec;
	std::string c = "check";
	std::ifstream fin;
	dec.createGroups("Groups.txt");
	dec.hireStudents("Students.txt");
	dec.addMarksToAll();
	dec.getStatistics();
	dec.saveStaff("Groups.txt", "Students.txt");
}