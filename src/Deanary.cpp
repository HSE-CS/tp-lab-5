// Copyright [2020] <Olesya Nikolaeva>

#include "Deanary.h"

void Deanary::createGroups(std::ifstream file) {
    std::string str, name, speciality;
    while (getline(file, str)) {
        name = str.substr(0, str.find(" "));
        speciality = str.substr(str.find(" ") + 1);
        groups.push_back(new Group(name, speciality));
    }
}

void Deanary::readStudents(std::ifstream file) {
    std::string str, groupName, ID, FIO;
    while (getline(file, str)) {
        groupName = str.substr(0, str.find("ID:") - 1);
        ID = str.substr(str.find("ID:") + 3, str.find("FIO:") - 1);
        FIO = str.substr(str.find("FIO:") + 4);
        findGroup(groupName)->addStudent(new Student(ID, FIO));
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
    unsigned int seed = time(NULL);
    for (auto group : this->groups) {
        for (auto student : group->students)
            student->addMark(rand_r(&seed) % 11);
    }
}

void Deanary::getStatistic() {
    for (auto i : groups) {
        std::cout << i->title << "'s average mark is "
        << i->averageGroupMark() << "\n" << std::endl;
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

void Deanary::saveStaff() {
    std::ofstream file("output.txt");
    if (file.is_open()) {
        for (auto i : groups) {
            file << "\n" << i->title << "'s average mark is "
            << i->averageGroupMark() << "\n" << std::endl;
            file << i->head->fio << " is a head of a group\n"
            << std::endl;
            for (auto j : i->students) {
                file << j->fio << "'s average mark is " <<
                j->averageMark() << std::endl;
            }
        }
    }
    file.close();
}

void Deanary::initHeads() {
    for (auto group : groups) {
        group->chooseHead();
    }
}

void Deanary::fireStudents(Student* unlucky) {
    auto index = std::find(unlucky->group->students.begin(),
                           unlucky->group->students.end(), unlucky);
    unlucky->group->students.erase(index);
}

Group* Deanary::findGroup(std::string name) {
    for (auto i : this->groups) {
        if (i->title == name) {
            return i;
        }
    }
    return 0;
}

Student* Deanary::findStudent(std::string name) {
    for (auto i : this->groups) {
        for (auto j : i->students) {
            if (j->fio == name) {
                return j;
            }
        }
    }
    return 0;
}

int Deanary::getStudentsNumber(std::string groupName) {
    Group* tmp = findGroup(groupName);
    return tmp->students.size();
}
