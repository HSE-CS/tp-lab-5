// Copyright 2021 Smirnov Grigory
#include "..\include\Group.h"

Group::Group(std::string title, std::string spec) {
	this->title=std::move(title);
	this->spec=std::move(spec);
}

Group::~Group() {
	for (int i = 0; i < students.size(); i++)
		if (students[i] != NULL) {
			delete students[i];
			students[i] == NULL;
		}
}

void Group::addStudent(Student* newPerson) {
	this->students.push_back(newPerson);
}

std::string Group::getTitle() {
	return this->title;
}

std::string Group::getSpec() {
	return this->spec;
}

void Group::chooseHead() {
	if (students.empty())
		throw "There are no students";
	std::random_device seed;
	head = students[seed() % students.size()];
}

double Group::getAverageMark() {
	if (students.empty()) 
		throw "There are no students";
	double sumAverages = 0;
	for (int i = 0; i < students.size(); i++)
		sumAverages += students[i]->getAverageMark();
	return sumAverages / students.size();
}

Student* Group::getStudent(int id) {
	Student* result=nullptr;
	for (int i = 0; i < students.size(); i++)
		if (students[i]->getId() == id) {
			result = students[i];
			break;
		}
	if (result == nullptr)
		throw "Student not found";
	return result;
}

Student* Group::getStudent(std::string fio) {
	Student* result = nullptr;
	for (int i = 0; i < students.size(); i++)
		if (students[i]->getFio() == fio) {
			result = students[i];
			break;
    }
	if (result == nullptr)
		throw "Student not found";
  return result;
}

void Group::removeStudent(int id) {
  int headFlag = 0;
  for (int i = 0; i < students.size(); i++)
    if (students[i]->getId() == id) {
			if (students[i]->isHeadOfGroup())
				headFlag = 1;
      students.erase(students.cbegin() + i);
      break;
    }
	if (headFlag==1)
    chooseHead();
}

void Group::removeStudent(std::string fio) {
	int headFlag = 0;
	for (int i = 0; i < students.size(); i++)
		if (students[i]->getFio() == fio) {
			if (students[i]->isHeadOfGroup())
				headFlag = 1;
			students.erase(students.cbegin() + i);
			break;
		}
	if (headFlag == 1)
		chooseHead();
}

bool Group::isEmpty() {
	return this->students.empty();
}

Student* Group::getHead() {
	return this->head;
}
