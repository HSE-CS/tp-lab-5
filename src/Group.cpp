// Copyright 2021 Vadukk

#include "../include/Group.h"


std::string Group::gettitle() {
    return title;
}

Group::Group(std::string titl, std::string sp) {
    this->title = titl;
    this->spec = sp;
    this->students = std::vector<Student*>();
}

void Group::addStudent(Student* newstudent) {
    this->students.push_back(newstudent);
}

Student* Group::getStudent(int id) {
    for (Student* st : this->students) {
        Student stu = *st;
        if (stu.getId() == id) return st;
    }
    throw "No Students in this group";
}

Student* Group::getStudent(std::string fio) {
    for (Student* st : this->students) {
        Student stu = *st;
        if (stu.getFio() == fio) return st;
    }
    throw "No Students in this group";
}

Student* Group::gethead() {
    return head;
}

Student* Group::chooseHead() {
    return this->students[0];
}

bool Group::isEmpty() {
    if (size(students) == 0) return 1;
    else
        return 0;
}

Student* Group::containsStudent(int id) {
    return getStudent(id);
}

Student* Group::containsStudent(std::string fio) {
    return getStudent(fio);
}

void Group::removeStudent(Student* stud) {
    int index = 0;
    for (Student* st : students) {
        index++;
        if (st == stud) break;
    }
    students.erase(students.begin() + index-1);
}

std::vector<Student*> Group::getstudents() {
    return students;
}

float Group::getAveragemark() {
    float i = 0;
    for (Student* st : students) {
        Student stu = *st;
        i += stu.getAveragemark();
    }
    return (i / size(students));
}
