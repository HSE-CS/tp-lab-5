// Copyright 7.02.2021 Golovanov

#include "Group.h"
#include <utility>


Group::Group(std::string title, std::string specialization)
: title(std::move(title)), specialization(std::move(specialization)) {}

const std::string& Group::GetTitle() const {
return title;
}

void Group::addStudent(Student* student) {
this->students.reserve(this->students.size() + 1);
this->students.push_back(student);
if (student->getGroup() != this) {
student->addToGroup(this);
}
}

Student* Group::getStudent(std::string stId) {
for (int i = 0; i < this->students.size(); ++i) {
if (this->students[i]->getId() == stId) {
return this->students[i];
}
}
return nullptr;
}

void Group::chooseHead(Student* head) {
this->head = head;
}

Student* Group::getHead() const {
return head;
}

double Group::calculateAverageMark() {
double sum = 0;
int counter = 0;
for (int i = 0; i < this->students.size(); ++i) {
sum += this->students[i]->calculateAverageMark();
counter++;
}
return sum / counter;
}

const std::vector<Student*>& Group::getStudents() const {
return students;
}

void Group::removeStudent(Student* student) {
student->setGroup(nullptr);
for (int i = 0; i < this->students.size(); ++i) {
if (this->students[i] == student) {
this->students.erase(this->students.begin() + i);
}
}
}
void Group::setTitle(const std::string& title) {
Group::title = title;
}
void Group::setSpecialization(const std::string& specialization) {
Group::specialization = specialization;
}

const std::string& Group::getSpecialization() const {
return specialization;
}

Group::~Group() = default;
