// Copyright 2021 Krayushkina
#pragma once

#include <vector>
#include<string>
#include <iostream>
using namespace std;
class Group;
class Deanery;
class Student 
{
private:
	int id;
	string fio;
	Group *group;
	vector<unsigned int> marks;
	int num;
public:
	Student(int id, string fio)
	{
		this->id = id;
		this->fio = fio;
		num = 0;
	}
	void CreateStudent(int id, string fio);
	void GroupEnrollment(Group *group);
	void AddMark(unsigned int mark);
	float AverageMark();
	friend Group;
	friend Deanery;
};