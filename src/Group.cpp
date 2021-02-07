// Copyright 2021 Kartseva Masha
#include "Group.h"
#include "Student.h"

Group::Group(std::string newName, std::string specName) {
    title = newName;
    spec = specName;
}

void Group::addStudent(Student* student) {
    students.push_back(student);
    student->setGroup(this);
}

void Group::expelStudent(Student* newStudent) {
    for (unsigned int i = 0; i < students.size(); i++) {
        if (newStudent == students[i]) {
            students.erase(students.begin() + i);
        }
    }
}

std::string Group::getTitle() const {
    return title;
}

std::string Group::getSpec() const {
    return spec;
}

std::string Group::getHeadName() const {
    return head->getName();
}

std::vector<Student*> Group::getStudents() const {
    return students;
}

void Group::chooseHead() {
    int num = rand() % (students.size());
    head = students[num];
}

unsigned int Group::AverageMarkofGroup() const {
    int res = 0;
    for (unsigned int i = 0; i < students.size(); i++) {
        res += students[i]->AverageMark();
    }
    res /= students.size();
    std::cout << " Average mark of " << 
    getTitle() << " is " << res << std::endl;
    return res;
}

Student* Group::findbyName(std::string name) const {
    for (unsigned int i = 0; i < students.size(); i++) {
        if (students[i]->getName() == name) return students[i];
    }
    std::cout << "This student is not in this group" << std::endl;
}

Student* Group::findbyId(int id) const {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i]->getId() == id) return students[i];
    }
    std::cout << "This student is not in this group" << std::endl;
}
