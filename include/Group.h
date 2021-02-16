#pragma once

#include <vector>
#include <string>
#include <iostream>

class Student;
class Group {
	friend class Deanary;
	friend class Student;
private:
	std::string title;
	std::string spec;
	std::vector <Student*> students;
	Student* head;
public:
	explicit Group(const std::string& t, const std::string& s);
	void addStudent(Student* student);
	void chooseHead(Student* student);
	double getAveragemark();
	Student* getStudent(const std::string& f);
	Student* getStudent(int id);
	void removeStudent(Student* student);
	bool isEmpty();
};