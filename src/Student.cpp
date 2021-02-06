// Copyright 2021 FOM

#include "Student.h"

Student::Student(int ID, std::string FIO) {
    this->ID = ID;
    this->FIO = FIO;
    this->marks = std::vector<int>();
    this->group = 0;
}

int Student::student_ID() {
    return ID;
}

std::string Student::student_FIO() {
    return FIO;
}

void Student::student_group(Group* group) {
    this->group = group;
}

void Student::add_mark(int mark) {
        marks.push_back(mark);   
}

double Student::student_mark_avarage() {
    int sum = 0;
    int count = 0;
    int res = 0;
    for (size_t i = 0; i < marks.size(); i++) {
        sum += marks[i];
        count++;
    }
    if (sum != 0) {
        res = sum / count;
    }
    else {
        res = 0;
    }
    return res;
  
}
