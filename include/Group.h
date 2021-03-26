// Copyright 2021 by Liza

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <vector>
#include <string>
#include "Deanary.h"
#include "Student.h"

class Student;

class Group {
	friend class Deanary;
	friend class Student;

public:
	Group() {}
	Group(std::string name, std::string speciality);
	void addStudent(Student* newStudent);
	void chooseHead();
	Student* containsStudent(std::string key);
	float getAveragemark();
	void removeStudent(std::string id);

private:
	std::string title;
	std::string spec;
	std::vector <Student*> students;
	Student* head;
};


#endif   // INCLUDE_GROUP_H_
