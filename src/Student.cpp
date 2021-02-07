// Copyright 2021 Kartseva Masha
#include "Student.h"

Student::Student(std::string newName, unsigned int newId) {
    name = newName;
    id = newId;
}

unsigned int Student::AverageMark() const {
    int res = 0;
    for (unsigned int i = 0; i < marks.size(); i++){
	    res += marks[i];
	}
    res /= marks.size();
    return res;
}

std::string Student::getName() const {
    return name;
}

unsigned int Student::getId() const {
    return id;
}

std::string Student::getGroup() const {
    return group->getTitle();
}

void Student::addMark(unsigned int newMark) {
    marks.push_back(newMark);
}

void Student::setGroup(Group* newGroup){
    group = newGroup;
}
