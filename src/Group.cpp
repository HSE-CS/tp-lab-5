// Copyright 2021 milalupehina
#include "Group.h"
#include "Student.h"

// добавление студента
void Group::addStudent(Student *neW) {
    students.push_back(neW);
};

// избрание старосты
void Group::chooseHead() {
    if (students.size() == 0) return;
    int num = rand() % students.size() + 0;
    this -> head = students[num];
};

// вычисление соеднего балла в группе
double Group::getAverageMark() {
    double rez = 0;
    int n = students.size();
    for ( auto &st : this->students) {
        rez+= st->getAverageMark();
    }
    if (n == 0) { return 0; } else { return rez/n; };
};

// исключение студента из группы
void Group::removeStudent(const int &id) {
    for ( auto &st : this->students) {
        if (st->id == id) {
            if (st->isHeadOfGroup()) {
                st->group->chooseHead();
            }
            st->addToGroup(nullptr);
            students.erase(students.begin() + (st->id--));
        }
    }
};

Student *Group::getStudent(const int &id) {
    for (auto &st : students) {
        if ( st->id == id ) {
            return st;
        }
    }
};

bool Group::isEmpty() {
    return students.empty();
};


