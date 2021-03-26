// Copyright 2021 Krayushkina
#pragma once

#include <vector>
#include<string>
#include <iostream>
#include "Student.h"
#include<random>
using namespace std;
class Group 
{
private:
	string title;
	vector<Student*>students;
	int num;
	Student *head;
public:
	Group(string title)
	{
		this->title = title;
		num = 0;
	}
	void CreateGroup(string title);
	void AddStudent(Student *,Group *);
	Student* HeadElection();
	Student* FindStudent(int id);
	float AverageInGroup();
	void StudentException(int id);
	friend Deanery;

};