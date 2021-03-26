// Copyright 2021 by Liza

#include "Student.h"

Student::Student(std::string ID, std::string FIO) {
	this->fio = new char[ID.length() + 1];
	this->id = ID;
	this->fio = new char[FIO.length() + 1];
	this->fio = FIO;
	this->group = nullptr;
}

void Student::addToGroup(Group* G) {
	this->group = G;
	G->students.push_back(this);
}

void Student::addmark(int mark) {
	this->marks.push_back(mark);
}

int Student::getAveragemark() {
	int mmark = 0;
	for (int n : marks)
		mmark += n;
	return (mmark - 1) / marks.size() + 1;
}

std::string Student::getGroup() {
	return this->group->title;
}