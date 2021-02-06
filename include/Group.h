// Copyright 2021 FOM

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <iostream>
#include <string>
#include <vector>

#include "Deanary.h"
#include "Student.h"

class Student;
class Deanary;

class Group {
private:
	std::string spec;
	std::string title;
	std::vector<Student*> students;
	Student* head;

public:
	void student_choice_head();
	void student_remove(Student* student);
	void student_add(Student* student);
	bool student_search_ID(int ID);
	bool student_search_FIO(std::string FIO);
	double mark_avarage();
	Group(std::string number_groups, std::string programm);
	std::string get_spec();
	std::string get_title();
	friend class Deanary;
	friend class Student;
};


#endif  // INCLUDE_GROUP_H_
