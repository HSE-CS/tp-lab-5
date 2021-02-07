#include "Group.h"
#include <sstream>


Group::Group(std::string name) {
    this->title = new char[name.length() + 1];
    //snprintf(this->title, name.length() + 1, "%s", name.c_str());
    this->title = name;
}

void Group::addSpeciality(std::string speciality) {
    this->spec = new char[speciality.length() + 1];
    //snprintf(this->spec, speciality.length() + 1, "%s", speciality.c_str());
    this->spec = speciality;
}

void Group::addStudent(Student* newStudent) {
    newStudent->group = this;
    this->students.push_back(newStudent);
}

void Group::chooseHead() {
    srand(0);
    int index = rand() % this->students.size();
    this->head = this->students[index];
}

Student* Group::find(std::string key) {
    for (auto i : students) {
        if ((i->fio == key) || (i->id == key)) {
            return i;
        }
    }
    return 0;
}

float Group::averageGroupMark() {
    float averages = 0.0;
    for (auto i : students) {
        averages += i->averageMark();
    }
    return averages / students.size();
}

void Group::goodbyeStudent(std::string id) {
    Student* student = find(id);
    auto index = std::find(students.begin(), students.end(), student);
    students.erase(index);
}
