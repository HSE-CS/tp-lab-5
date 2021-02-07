#include "Daenary.h"

void Deanary::createGroups(std::ifstream file) {
    std::string str, name, speciality;
    while (getline(file, str)) {
        name = str.substr(0, str.find(" ") - 1);
        speciality = str.substr(str.find(" ") + 1);
        Group newOne(name);
        newOne.addSpeciality(speciality);
        this->groups.push_back(&newOne);
    }
}

void Deanary::readStudents(std::ifstream file) {
    std::string str, groupName, ID, FIO;
    while (getline(file, str)) {
        groupName = str.substr(0, str.find("ID:") - 1);
        ID = str.substr(str.find("ID:") + 3, str.find("FIO:") - 1);
        FIO = str.substr(str.find("FIO:") + 4);
        Student newOne(ID, FIO);
        addStudents(&newOne, groupName);
    }
}

void Deanary::addGroup(Group* name) {
    groups.push_back(name);
}

void Deanary::addStudents(Student* newOne, std::string groupName) {
    for (auto i : groups) {
        if (i->title == groupName) {
            i->addStudent(newOne);
            return;
        }
    }
}

void Deanary::addMarksToAll() {
    for (auto group : this->groups) {
        for (auto student : group->students)
            student->addMark(rand() % 11);
    }
}

void Deanary::getStatistic() {
    for (auto i : groups) {
        std::cout << i->title << "'s average mark is "
        << i->averageGroupMark() << "/n" << std::endl;
        for (auto j : i->students) {
            std::cout << j->fio << "'s average mark is " <<
            j->averageMark() << std::endl;
        }
        puts("");
    }
}

void Deanary::moveStudents(Student* student, std::string groupName) {
    (student->group)->goodbyeStudent(student->id);
    addStudents(student, groupName);
}

void saveStaff();

void Deanary::initHeads(std::string, std::string) {
    for (auto group : groups) {
        group->chooseHead();
    }
}

void fireStudents(std::string, std::string);

Student* getStudent(std::string, std::string);

Group* Deanary::getGroup(std::string name) {
    for (auto i : groups) {
        if (i->title == name) {
            return i;
        }
    }
    return 0;
}
