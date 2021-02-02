// Copyright 2021 Smirnov Grigory
#include "..\include\Student.h"
#include "..\include\Group.h"

Student::Student(int id, std::string fio) {
	this->id = id;
	this->fio = std::move(fio);
}

int Student::getId() {
  return this->id;
}

std::string Student::getFio() {
  return this->fio;
}

void Student::addMark(int mark) {
  this->marks.push_back(mark);
}

void Student::addToGroup(Group* new_group) {
	this->group = new_group;
}

double Student::getAverageMark() {
	if (marks.empty())
		throw "Student does not have marks";
	int sumMarks = 0;
	for (int mark : marks)
		sumMarks += mark;
	return ((double)sumMarks / marks.size());
}

bool Student::isHeadOfGroup() {
  return group != nullptr && this == group->getHead();
}

std::string Student::getInfo() {
  return std::to_string(getId()) + " " + getFio() + " "
	  + group->getSpec() + " " + group->getTitle()
	  + " Average Mark: " + std::to_string(getAverageMark());
}
