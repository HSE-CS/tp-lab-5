// Copyright Roman Balayan @ 2021

#include "../include/Group.h"

Group::Group(const std::string title) : title(title)
{

}

Group::Group(const std::string title, const std::string spec) : title(title), spec(spec)
{
}

void Group::addStudent(std::shared_ptr<Student> student)
{
    this->students.push_back(student);
}

bool Group::selectHead(std::shared_ptr<Student> newHead)
{
    this->head = newHead;
    return true;
}

std::shared_ptr<Student> Group::findStudent(const std::string name) const
{
    auto result = std::find_if(this->students.begin(), this->students.end(), [name](std::shared_ptr<Student> st) {return st->getName() == name; });
    return *result;
    return nullptr;
}

std::shared_ptr<Student> Group::findStudent(short id) const
{
    auto result = std::find_if(this->students.begin(), this->students.end(), [id](std::shared_ptr<Student> st) {return st->getId() == id; });
    return *result;
}

double Group::getAverageScore() const
{
    double sum = 0;
    for (auto it = this->students.begin(); it != this->students.end(); ++it) {
        sum += (*it)->getAverageMark();
    }
    return sum / this->students.size();
}

bool Group::removeStudent(std::shared_ptr<Student> student)
{
    if (!student)
        return false;
    this->students.erase(std::remove(this->students.begin(), this->students.end(), student), this->students.end());
    return true;
}

bool Group::removeStudent(const std::string name)
{
    return this->removeStudent(this->findStudent(name)); 
}

bool Group::removeStudent(short id)
{
    return this->removeStudent(this->findStudent(id));
}

void Group::printStudents() const
{
    for (auto it = this->students.begin(); it != this->students.end(); ++it)
        (*it)->printStudent();
}


