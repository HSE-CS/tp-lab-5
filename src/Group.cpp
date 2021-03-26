// Copyright 2021 by Liza

#include "Group.h"
#include <sstream>


Group::Group(std::string name, std::string speciality) {
this->title = new char[name.length() + 1];
this->title = name;
this->spec = new char[speciality.length() + 1];
this->spec = speciality;}

void Group::addStudent(Student* newStudent) {
newStudent->group = this;
this->students.push_back(newStudent);}

void Group::chooseHead() {
unsigned int seed = time(NULL);
int index = rand_r(&seed) % this->students.size();
this->head = this->students[index];}

Student* Group::containsStudent(std::string key) {
for (auto i : students) {
if ((i->fio == key) || (i->id == key)) {
return i;}}
return 0;}

float Group::getAveragemark() {
float mmark = 0.0;
for (auto i : students) {
mmark += i->getAveragemark();}
return mmark / students.size();}

void Group::removeStudent(std::string id) {
Student* student = containsStudent(id);
auto index = std::find(students.begin(), students.end(), student);
students.erase(index);}