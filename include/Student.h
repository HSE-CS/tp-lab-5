//  Copyright 2020 Baklanov
#ifndef INCLUDE_Student_
#define INCLUDE_Student_

#include "Group.h"
#include "Deanary.h"
#include <iostream>
#include <vector>

class Group;

class Student {
private:
	int id = -1;
	std::string fio;
	Group *group;
	std::vector<int> marks;
	std::string intel = "";
	void addToGroup(Group& A);
	bool isHead = 0;
public:
	void addmark(int mark);
	Student(int num, std::string fi, Group* gr, int intellect);
	Student(int num, std::string fi);
	double getAvearagemark();
	bool isHeadOfGroup();
	int getId() {
		return id;
	}
	friend class Deanary;
	friend class Group;
};

#endif
