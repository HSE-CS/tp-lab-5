#include "Student.h"


Student::Student(int input_id, const std::string& input_fio) {
    this->id = input_id;
    this->fio = input_fio;
    this->group = nullptr;
}

void Student::addToGroup(Group *group) {
    this->group = group;
}

void Student::addMark(int mark) {
    if (mark <= 10 and mark > 0) this->marks.push_back(mark);
}

double Student::getAverageMark() {
    int sum = 0;
    double result;
    for (int mark : this->marks) {
        sum += mark;
    }
    return !this->marks.empty() ? sum / static_cast<double>(this->marks.size()) : 0;
}

int Student::getId() const {
    return this->id;
}

std::string Student::getName() const {
    return this->fio;
}





