// Copyright 2021 Stifeev Nikita

#include "Student.h"

Student::Student(int ID, std::string full_name)
{
    Id = ID;
    FIO = full_name;
}

void Student::addToGroup(Group* group)
{
    this->group = group;
}

void Student::addmark(int mark)
{
    marks.push_back(mark);
}

int Student::calcAv() const
{
    long unsigned int num = marks.size();
    long unsigned int sum = 0;
    for (long unsigned int i = 0; i < num; i++)
    {
        sum += marks[i];
    }
    int res = sum / num;
    return res;
}

std::string Student::getFIO() const
{
    return FIO;
}

unsigned int Student::getID() const
{
    return Id;
}

Group* Student::getGroup() const
{
    return this->group;
}

Student::~Student()
{
}
