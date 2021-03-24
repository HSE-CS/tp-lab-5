#include "Student.h"
#include "Group.h"

Group::Group(const std::string& t, const std::string& s) 
{
	title = t;
	spec = s;
}

void Group::addStudent(Student* student) 
{
	students.push_back(student);
	student->addToGroup(this);
}
void Group::chooseHead(Student* student) 
{
	head = student;
}

double Group::getAveragemark() 
{
	int count = students.size();
	double res = 0.0;
	for (auto student : students) 
	{
		res += student->getAveragemark();
	}
	return res / count;
}

Student* Group::getStudent(int id) 
{
	for (auto s : students) 
	{
		if (s->getId() == id)
			return s;
	}
	return nullptr;
}

Student* Group::getStudent(const std::string& fio) 
{
	for (auto s : students) 
	{
		if (s->getName() == fio)
			return s;
	}
	return nullptr;
}

void Group::removeStudent(Student* student) 
{
	if (student == head)
		head = nullptr;
	for (int i = 0; i < students.size(); i++) 
	{
		if (students[i] == student) 
		{
			students.erase(students.begin() + i);
		}
	}
}

bool Group::isEmpty() 
{
	return students.size() == 0;
}