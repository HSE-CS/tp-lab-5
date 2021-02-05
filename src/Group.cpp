// Copyright 2021 Igumnova Natasha
#include "Group.h"

void Student::addmark(int mark) {
    this->marks.push_back(mark);
}
void Group::addStudent(Student* student_) {
    this->students.push_back(student_);
    student_->addToGroup(this);
}
void Group::chooseHead() {
	int head_i = 0;
    if (students.size()) {
        head_i = std::rand() % students.size();
    }
    head = students.at(head_i);
}
std::string Group::getTitle() {
    return this->title;
}
void Group::removeStudent(Student* student_) {
    bool head_flag = false;
    for (int i = 0;i < this->students.size();i++) {
        if (students[i]->getId() == student_->getId()) {
            if (students[i]->getFio() == this->head->getFio())
                 head_flag = true;
            students[i]->addToGroup(nullptr);
            students.erase(students.begin() + i);
            break;
        }
    }
    if (head_flag) {
        this->chooseHead();
    }
}

double Group::getAvaragemark() {
    double sum = 0.0;
	if (students.size()) {
		for (int i = 0;i < students.size();i++) {
			sum += students[i]->getAveragemark();
		}
		return sum / students.size();
    }
    return 0.0;
}
Student* Group::getStudent(int id_) {
    for (int i = 0;i < students.size();i++) {
        if (students[i]->getId() == id_)
            return students[i];
    }
    return nullptr;
}
bool Group::containsStudents(Student* st) {
    for (int i = 0;i < students.size();i++) {
        if (students[i]->getId() == st->id)
            return true;
    }
    return false;
}
bool Group::isEmpty() {
    return this->students.size() == 0;
}