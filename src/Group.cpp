//  Copyright 2020 Baklanov

#include "Group.h"
#include <random>

void Group::addStudent(Student *s) {
students.push_back(s);
}

void Group::AddStudent(Student* s) {
students.push_back(s);
}

void Group::removeStudent(Student* a) {
int size = this->students.size();
int idGetToInt = 0;
for (unsigned int i = 0; i < students.size(); ++i) {
if (a == students[i]) {
students.erase(students.begin() + i);
delete a;
break;
}
}
}

double Group::getAveragemark() {
double sum = 0;
int size = this->students.size();
for (int i = 0; i < size; ++i) {
if (students[i]->getAvearagemark()) {
sum += students[i]->getAvearagemark();
}
}
if ((size == 0) || (sum == 0)) {
return 0;
}
return sum / size;
}

Student* Group::getStudent(std::string student) {
if (!containsStudent(student))
return NULL;
int size = this->students.size();
if ((student[0] >= '0') || (student[0] <= '9')) {
int idGetToInt = 0;
for (int i = 0; i < student.length(); ++i) {
static_cast<int>(student[0]);
idGetToInt = (student[0] - 48) * pow(10, student.length() - i - 1);
}
for (int i = 0; i < size; ++i) {
if (idGetToInt == students[i]->id) {
return students[i];
}
}
} else {
for (int i = 0; i < size; ++i) {
if (student == students[i]->fio) {
return students[i];
}
}
}
}

void Group::chooseHead(int number) {
students[number]->isHead = true;
head = students[number];
}

void Group::chooseHeadTest(int number) {
students[number]->isHead = true;
head = students[number];
}

bool Group::containsStudent(std::string student) {
int size = this->students.size();
if ((student[0] >= '0') || (student[0] <= '9')) {
int idGetToInt = 0;
for (unsigned int i = 0; i < student.length(); ++i) {
static_cast<int>(student[0]);
idGetToInt = (student[0] - 48) * pow(10, student.length() - i - 1);
}
for (int i = 0; i < size; ++i) {
if (idGetToInt == students[i]->id) {
return true;
}
}
} else {
for (int i = 0; i < size; ++i) {
if (student == students[i]->fio) {
return true;
}
}
}
return false;
}

bool Group::isEmpty() {
return this->students.size();
}
