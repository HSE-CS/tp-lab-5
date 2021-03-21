//
// Created by mushka on 19.03.2021.
//

#include "../include/Student.h"


Student::Student(int new_id, std::string new_fio) {
    this->id = new_id;
    this->fio = std::move(new_fio);
}


void Student::AddToGroup(Group *new_group) {
    this->group = new_group;
}

void Student::AddMark(int mark) {
    marks.push_back(mark);
}

float Student::CountAvgMark() {
    if (marks.empty()) return 0;

    float sum = 0;
    unsigned int len = marks.size();
    for (int i = 0; i < len; i++) {
        sum += static_cast<float>(marks[i]);
    }

    return sum / static_cast<float>(len);
}


int Student::GetId() const {
    return id;
}

std::string Student::GetFio() {
    return fio;
}
