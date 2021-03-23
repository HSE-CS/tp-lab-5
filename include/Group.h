// Copyright 2021 Vadukk

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include "Student.h"

class Student;

class Group {
private:
	std::string spec;
	std::string title;
	std::vector<Student*> students;
	Student* head;
public:
	std::string gettitle();
	Group(std::string titl, std::string sp);
	void addStudent(Student* newstudent);
	Student *getStudent(int id);
	Student *getStudent(std::string fio);
	Student *chooseHead();
	Student* gethead();
	float getAveragemark(); 
	Student* containsStudent(std::string fio);
	Student* containsStudent(int id);
	void removeStudent(Student *stud);
	std::vector<Student*> getstudents();
	bool isEmpty();
};

#endif  // INCLUDE_GROUP_H_
