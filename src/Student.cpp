// Copyright 2021 milalupehina

#include "Student.h"



// зачисление в группу
void Student::addToGroup(Group* hisGroup) {
    this -> group = hisGroup;
}

// добавление оценки
void Student::addMark(int mark) {
    this -> marks.push_back(mark);
}

// вычисление средней оценки
double Student::getAverageMark() {
    double sum = 0;
    int num = marks.size();
    for (int i = 0; i < num; ++i) {
        sum += marks[i];
    }

    return sum / num;
}

bool Student::isHeadOfGroup() {
    if (group != NULL && id == group->head->id) {
        return true;
    } else {
        return false;
    }
}

