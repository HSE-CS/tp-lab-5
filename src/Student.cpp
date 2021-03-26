// Copyright 2021 Krayushkina
#include <vector>
#include<string>
#include "Student.h"

void Student::CreateStudent(int id, string fio)
{
	this->id = id;
	this->fio = fio;
}
void Student::AddMark(unsigned int mark)
{
	marks.push_back(mark);
	num++;
}
float Student::AverageMark()
{
	float sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum += marks[i];
	}
	return sum / num;
}

void Student::GroupEnrollment(Group *group)
{
	this->group = group;
}