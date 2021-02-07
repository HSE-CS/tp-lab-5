#include "Deanary.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void Deanary::createGroups(std::string path)
{
    std::string title;
    std::ifstream file(path);
    while (getline(file, title)) {
        std::string spec;
        getline(file, spec);
        Group gr(title, spec);
        groups.push_back(gr);
    }
}

void Deanary::hireStudents(std::string path)
{
    int i = 1;
    std::string fio;
    std::ifstream file(path);
    while (getline(file, fio)) {
        Student student(fio,i);
        students.push_back(student);
        i++;
    }
}

void Deanary::addMarkToAll()
{
    srand(time(NULL));
    int count = rand() % 20;
    std::vector<int> marks;
    for (int i = 0; i < students.size(); i++) 
    {
        for (int j = 0; j < count; j++) 
        {
            marks.push_back(rand() % 10);
        }
        students[i].setMarks(marks);

    }
}

std::string Deanary::getStatisticsByStudent(std::string fio)
{
    std::stringstream stream;
    for (int i = 0; i < students.size(); i++) 
    {
        if (students[i].getFio() == fio) 
        {
            stream << "Fio: " << fio << ", group: " << students[i].getGroupTitle() << ", average mark: " << students[i].getAverageMark() << "\n";
            return stream.str();
        }
    }
    return std::string();
}

std::string Deanary::getStatisticsByGroup(std::string title)
{
    std::stringstream stream;
    for (int i = 0; i < groups.size(); i++) 
    {
        if (groups[i].getTitle() == title) 
        {
            stream << "Title: " << groups[i].getTitle() << " spec: " << groups[i].getSpec() << " average mark: " << groups[i].getAverageMark() << "\n";
            return stream.str();
        }
    }
    return std::string();
}

void Deanary::moveStudent(std::string fio, std::string title)
{
    for (int i = 0; i < students.size(); i++) 
    {
        if (students[i].getFio() == fio) 
        {
            auto t = students[i].getGroupTitle();
            if (t != "-1") 
            {
                for (int j = 0; j < groups.size(); j++) 
                {
                    if (groups[j].getTitle() == t)
                        groups[j].removeStudent(students[i]);
                }
            }
            for (int j = 0; j < groups.size(); j++) 
            {
                if (groups[j].getTitle() == title) {
                    groups[j].addStudent(students[i]);
                    return;
                }
            }
        }
    }
}
void Deanary::moveStudents()
{
    srand(time(NULL));
    for (int i = 0; i < students.size(); i++) 
    {
        int num = rand() % (groups.size());
        moveStudent(students[i].getFio(), groups[num].getTitle());
    }
}

void Deanary::initHead()
{
    for (int i = 0; i < groups.size(); i++)
        groups[i].chooseHead();
}

void Deanary::saveStuff(std::string path)
{
    std::ofstream fout;
    fout.open(path);
    for (int i = 0; i < groups.size(); i++) 
    {
        fout << "-------------Group--------------------" << std::endl;
        fout << "Title: " << groups[i].getTitle() << ", spec: " << groups[i].getSpec() << std::endl;
        fout << "Head of group: " << groups[i].getHead()->getFio() << std::endl;
        for (int j = 0; j < groups[i].getStudents().size(); j++) 
        {
            fout << "Fio: " << groups[i].getStudents()[j].getFio() << std::endl;
        }
    }
}

void Deanary::printInfo()
{
    for (int i = 0; i < groups.size(); i++) 
    {
        std::cout << "-------Group---------" << std::endl;
        std::cout << getStatisticsByGroup(groups[i].getTitle()) << std::endl;
        for (int j = 0; j < groups[i].getStudents().size(); j++) 
        {
            std::cout << getStatisticsByStudent(groups[i].getStudents()[j].getFio());
        }
    }
}

void Deanary::fireStudent()
{
    for (int i = 0; i < groups.size(); i++) 
    {
        auto students = groups[i].getStudents();
        for (int j = 0; j < students.size(); j++) 
        {
            if (students[j].getAverageMark() < 3) 
            {
                groups[i].removeStudent(students[j]);
            }
        }
    }
}

void Deanary::addGroup(Group& group)
{
    groups.push_back(group);
}

std::vector<Group> Deanary::getGroups()
{
    return groups;
}

void Deanary::addStudent(Student& student)
{
    students.push_back(student);
}
