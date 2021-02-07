// Copyright 2021 Kris

#include "Student.h"

Student::Student(int id_new, std::string fio_new) {
    this->id = id_new;
    this->fio = fio_new;
    this->marks = std::vector<int>();
}


void Student::addToGroup(Group* gr) {
    this->group = gr;
}

std::string Student::getFiofromId(int id) {
    Group gr = *(this->group);
    Student* st = gr.getStudent(id);
    //Student stu = *st;
    if (st) {
        Student stu = *st;
        return stu.getFio();
    }
    else return "No such Student";
}

int Student::getId() {
    return this->id;
}

std::string Student::getFio() {
    return this->fio;
}

void Student::addmark(int mark) {
    this->marks.push_back(mark);
}

float Student::getAveragemark() {
    float i = 0;
    for (int mark: this->marks) {
        i += mark;
    }
    return (i / size(marks));
}

int Student::isHeadOfGroup() {
    Group gr = *(this->group);
    Student* head = gr.gethead();
    Student st = *head;
    if (this->id == st.getId()) return 1;
    else return 0;
}

Group* Student::getGroup() {
    return group;
}



