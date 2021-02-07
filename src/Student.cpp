#include "Student.h"

double Student::getAveragemark() {
    double sum = 0;
    for (int i = 0; i < marks.size(); i++) {
        sum += marks[i];
    }
    return sum / marks.size();
}
bool Student::isHeadOfGroup() {
    if (this->group->head->id == this->id) {
        return true;
    }
    else {
        return false;
    }
}
Student::Student() {
    id = -1;
}
Student::Student(std::string fio) {
    this->fio = fio;
}
Student::Student(int id, std::string fio) {
    this->id = id;
    this->fio = fio;
}
Student::Student(int id, std::string fio, Group* group) {
    this->id = id;
    this->fio = fio;
    this->group = group;
}
Student::Student(int id, std::string fio, std::vector<int> marks) {
    this->id = id;
    this->fio = fio;
    this->group = group;
    this->marks = marks;
}
Student::Student(int id, std::string fio, Group* group, std::vector<int> marks) {
    this->id = id;
    this->fio = fio;
    this->group = group;
    this->marks = marks;
}
void Student::addToGroup(Group* group) {
    this->group = group;
}
void Student::addmark(int mark) {
    marks.push_back(mark);
}

int Student::getId() {
    return id;
}

std::string Student::getFio() {
    return fio;
}