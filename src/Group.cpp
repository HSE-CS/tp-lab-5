// Copyright 2021 Krayushkina
#include <vector>
#include<string>
#include "Group.h"
void Group::CreateGroup(string title)
{
	this->title = title;
	num = 0;
}
void Group::AddStudent(Student *st, Group *group)
{
	students.push_back(st);
	students.back()->GroupEnrollment(group);
	num++;
}
Student* Group::HeadElection()
{
	random_device ran;
	head = students[ran()%num];
	return head;
}
Student* Group::FindStudent(int id)
{
	for (int i = 0; i < num; i++)
	{
		if (students[i]->id == id)
			return students[i];
		if (i == num - 1)
		{
			cout << "Íå íàéäåí"<<endl;
			return 0;
		}
	}
}
float Group::AverageInGroup()
{
	float sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum += students[i]->AverageMark();
	}
	if (num == 0)
		return sum;
	else
		return sum / num;
}
void Group::StudentException(int id)
{
	for (int i = 0; i < num; i++) 
	{
		if (students[i]->id == id)
		{
			students.erase(students.begin() + i);
			num--;
		}
	}
}
