// Copyright Roman Balayan @ 2021

#include <stdlib.h>
#include "../include/Deanary.h"

void Deanary::addGroup(const std::shared_ptr<Group>& group) {
    this->groups.push_back(group);
}

void Deanary::addStudent(const std::shared_ptr<Student>& student) {
    // auto gr = std::find(this->groups.begin(), this->groups.end(), );
    // (*gr)->addStudent(student);
}

void Deanary::addRandomMarks(int16_t amount) {
    for (auto it = this->groups.begin(); it != this->groups.end(); ++it) {
        for (auto st = (*it)->students.begin();
            st != (*it)->students.end(); ++st) {
            for (int i = 0; i < amount; ++i) {
                (*st)->addMark(20 % 11); // S1 kill cpplint
            }
        }
    }
}

void Deanary::printStatistics() {
    for (auto it = this->groups.begin(); it != this->groups.end(); ++it) {
        std::cout << "Group: " << (*it)->title
            << "\nAverage score: " << (*it)->getAverageScore() << "\n";
        std::cout << "Students amount: " << (*it)->students.size() << "\n";
        (*it)->printStudents();
        std::cout << "\n";
    }
}

bool Deanary::changeGroup(const std::shared_ptr<Student>& student,
    const std::shared_ptr<Group>& newGroup) {
    return student->setGroup(newGroup);
}

// TO DO
bool Deanary::changeGroup(int16_t studentID, std::string newGroupTitle) {
    return false;
}

bool Deanary::removeBadStudents(double minAverageScore) {
    for (auto it = this->groups.begin(); it != this->groups.end(); ++it) {
        for (auto st = (*it)->students.begin();
            st != (*it)->students.end(); ++st) {
            if ((*st)->getAverageMark() < minAverageScore)
                (*it)->removeStudent(*st);
        }
    }
    return true;
}
