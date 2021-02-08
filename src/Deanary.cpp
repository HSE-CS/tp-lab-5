#include "Deanary.h"

// Copyright Roman Balayan @ 2021

void Deanary::addGroup(std::shared_ptr<Group>& group)
{
    this->groups.push_back(group);
}

void Deanary::addStudent(std::shared_ptr<Student>& student)
{
    auto gr = std::find(this->groups.begin(), this->groups.end(), student->getGroup());
    (*gr)->addStudent(student);
}

void Deanary::addRandomMarks(short amount)
{
    for (auto it = this->groups.begin(); it != this->groups.end(); ++it) {
        for (auto st = (*it)->students.begin(); st != (*it)->students.end(); ++st) {
            for (int i = 0; i < amount; ++i) {
                (*st)->addMark(rand() % 11);
            }
        }
    }
}

void Deanary::printStatistics()
{
    for (auto it = this->groups.begin(); it != this->groups.end(); ++it) {
        std::cout << "Group: " << (*it)->title << "\nAverage score: " << (*it)->getAverageScore() << "\n";
        std::cout << "Students amount: " << (*it)->students.size() << "\n";
        (*it)->printStudents();
        std::cout << "\n";
    }
}

bool Deanary::changeGroup(std::shared_ptr<Student>& student, std::shared_ptr<Group>& newGroup)
{
    student->setGroup(newGroup);
}

// TO DO
bool Deanary::changeGroup(short studentID, std::string newGroupTitle)
{
    return false;
}

bool Deanary::removeBadStudents(double minAverageScore)
{
    for (auto it = this->groups.begin(); it != this->groups.end(); ++it) {
        for (auto st = (*it)->students.begin(); st != (*it)->students.end(); ++st) {
            if ((*st)->getAverageMark() < minAverageScore)
                (*it)->removeStudent(*st);
        }
    }
}
