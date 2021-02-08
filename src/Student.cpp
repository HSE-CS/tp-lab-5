#include "../include/Student.h"

// Copyright Roman Balayan @ 2021

Student::Student(const std::string name) : name(name)
{
    this->id = id_generator++;
}

Student::Student(const std::string name, const std::vector<int16_t>& marks) : name(name), marks(marks)
{
    this->id = id_generator++;
}

Student::Student(const std::string name, const std::shared_ptr<Group>& group) : name(name), group(group)
{
    this->id = id_generator++;
}

Student::Student(const std::string name, const std::shared_ptr<Group>& group, const std::vector<int16_t>& marks) : name(name), group(group), marks(marks)
{
    this->id = id_generator++;
}

bool Student::setGroup(const std::shared_ptr<Group>& group)
{
    this->group = group;
    return true;
}

void Student::addMark(const int16_t mark)
{
    this->marks.push_back(mark);
}

void Student::printStudent() const
{
    std::cout << this->name << " : ";
    for (auto it = this->marks.begin(); it != this->marks.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

float Student::getAverageMark() const
{
    return static_cast<float>( std::accumulate(this->marks.begin(), this->marks.end(), 0) ) / this->marks.size();
}

std::string Student::getName() const
{
    return this->name;
}

u_int Student::getId() const
{
    return this->id;
}

std::weak_ptr<Group> Student::getGroup() const
{
    return this->group;
}

u_int Student::id_generator{ 0 };