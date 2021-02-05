//  Copyright 2020 Baklanov

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include "Student.h"
#include "Deanary.h"
#include <iostream>
#include <vector>
#include <string>

class Student;

class Group {
 private:
std::string title;
std::string spec;
std::vector<Student*> students;
Student* head {};
int acadPerform;
void addStudent(Student* s);
void removeStudent(Student* a);
void chooseHead(int number);
	
 public:
void chooseHeadTest(int number);
double getAveragemark();
void AddStudent(Student* s);
Student* getStudent(std::string student);
bool containsStudent(std::string student);
Student* getHead() {
return head;
}
bool isEmpty();
friend class Deanary;
};

#endif // INCLUDE_GROUP_H_
