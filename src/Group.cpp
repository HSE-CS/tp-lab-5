#include "Group.h"
#include <iostream>

Group::Group(std::string title, std::string spec) {
	this->title = title;
	this->spec = spec;
}

void Group::addStudent(Student& student) {
	student.addToGroup(this);
	students.push_back(student);
}

void Group::chooseHead() {
	srand(time(NULL));
	int num = rand() % (students.size());
	this->head = &(students[num]);

}

Student& Group::getStudent(int id) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getId() == id) {
			return students[i];
		}
	}
}

Student& Group::getStudent(std::string fio) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getFio() == fio) {
			return students[i];
		}
	}
}

double Group::getAverageMark() {
	double sum = 0.0;
	for (int i = 0; i < students.size(); i++) {
		sum += students[i].getAverageMark();
	}
	return sum / students.size();
}

void Group::removeStudent(Student& student) {
	auto iter = students.begin();
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getId() == student.getId()) {
			students.erase(iter + i);
			student.removeGroup();
		}
	}
}

std::string Group::getTitle() {
	return title;
}

std::string Group::getSpec() {
	return spec;
}

Student* Group::getHead() {
	return head;
}

std::vector<Student> Group::getStudents() {
	return students;
}
