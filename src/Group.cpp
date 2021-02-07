// Copyright 06.02.21 DenisKabanov

#include "Group.h"
#include "Student.h"

Group::Group(std::string newtitle) {
    this->title = newtitle;
}

void Group::addspec(std::string newspec) {
    this->spec = newspec;
}

Group::Group(std::string newtitle, std::string newspec) {
    title = newtitle;
    spec = newspec;
}

int Group::getStudents() {
    int studcount = 0;
    for (auto members : this->students) {
        studcount++;
    }
    return studcount;
}

void Group::addStudent(Student* newstudent) {
    if (this->getStudent(newstudent->getId()) == nullptr) {
        students.push_back(newstudent);
        newstudent->addToGroup(this);
    }
}

void Group::chooseHead() {
    std::mt19937 gen(time(0));
    std::uniform_int_distribution<> uid(0, students.size() - 1);
    head = students[uid(gen)];
}

float Group::getAveragemark() {
    float sum = 0;
    for (auto stud : students) {
        sum = sum + stud->getAveragemark();
    }
    if (sum != 0)
        return (sum / this->getStudents());
    else
        return 0;
}

Student* Group::getStudent(unsigned int findid) {
    for (auto stud : students) {
        if (stud->getId() == findid)
            return stud;
    }
    return nullptr;
}

Student* Group::getStudent(std::string findfio) {
    for (auto stud : students) {
        if (stud->getFio() == findfio)
            return stud;
    }
    return nullptr;
}

Student* Group::getHead() {
    return head;
}

std::vector<Student*> Group::containsStudents() {
    return students;
}

std::string Group::getTitle() {
    return title;
}

std::string Group::getSpec() {
    return spec;
}

void Group::removeStudent(Student* delstudent) {
    delstudent->addToGroup(nullptr);
    students.erase(std::remove(students.begin(), students.end(), delstudent),
students.end());
}

bool Group::isEmpty() {
    if (students.size() == 0)
        return true;
    else
        return false;
}
