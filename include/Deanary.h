// Copyright 2021 Krayushkina
#pragma once

#include <vector>
#include <iostream>
#include "Student.h"
#include "Group.h"
#include<fstream>
#include<string>
using namespace std;
class Deanery
{
private:
	int num_groups;
	int num_students;
	vector<Student*>students;
	vector<Group*>groups;
public:
	Deanery() 
	{
		num_groups = 0;
		num_students = 0;
		vector<Student*>students;
		vector<Group*>groups;
	}
	void CreateStudentsFromFile();
	void CreateGroupsFromFile();
	void AddMarks();
	void GetStatistic(string thing);
	void StudentTransferToGroup(int id,string group);
	void StudentDeduction();
	void SaveDataInFiles();
	void ChooseHeads();
	void DataOutput();

};