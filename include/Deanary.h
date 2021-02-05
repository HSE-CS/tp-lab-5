//  Copyright 2020 Baklanov
#ifndef INCLUDE_Deanary_
#define INCLUDE_Deanary_

#include "Group.h"
#include "Student.h"
#include <iostream>
#include <vector>

class Group;

class Student;

class Deanary {
private:
	std::vector<Group> groups;
public:
	void createGroups(std::string path);
	void hireStudents(std::string path);
	void addMarksToAll();
	double getStatistics();
	void moveStudents();
	void saveStaff(std::string pathGroup, std::string pathStudent);
	void initHeads();
	void fireStudents(int number);
	Group* getGroup(int number) {
		return &groups[number];
	}
};

#endif
