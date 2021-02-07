#include "Student.h"

Student::Student(std::string ID, std::string FIO) {
    this->fio = new char[ID.length() + 1];
    this->id = ID;
    this->fio = new char[FIO.length() + 1];
    //snprintf(this->fio, FIO.length() + 1, "%s", FIO.c_str());
    this->fio = FIO;
    this->group = nullptr;
}

void Student::groupIs(Group* G) {
    this->group = G;
    G->students.push_back(this);
}

void Student::addMark(uint64_t mark) {
    this->marks.push_back(mark);
}

float Student::averageMark() {
    int average = 0;
    for (int n : marks)
        average += n;
    return average / marks.size();
}
