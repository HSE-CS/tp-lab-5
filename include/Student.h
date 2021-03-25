// Copyright 2021 by Maxim


#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <iostream>
#include <vector>
#include <string>
#include "Group.h"

class Student {
 private:
    int id;
    std::string fio;
    Group *group;
    std::vector<int> marks;

 public:
    Student(int id, const std::string fio) {
        this->id = id;
        this->fio = fio;
        this->group = nullptr;
    }

    std::string getFIO() {
        return fio;
    }

    int getID() {
        return this->id;
    }

    void addmark(int mark) {
        this->marks.push_back(mark);
    }

    double getAveragemark() {
        double sum = 0;
        for (auto el : marks) {
            sum += el;
        }
        return sum / marks.size();
    }

    void addToGroup(Group *group) {
        this->group = group;
    }
};

#endif  // INCLUDE_STUDENT_H_
