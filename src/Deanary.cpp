// Copyright 2021 milalupehina
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

#include "Deanary.h"

// Разработать класс Deanery

// создание групп на основе данных из файла
void Deanery::createGroups() {
    std::ifstream grData;
    grData.open("../data/departments.txt");

    std::string grName;
    std::string depName;

    if (grData.is_open()) {
        for (int i = 0; i < 4; ++i) {
            grData >> grName;
            grData >> depName;
            Group *n = new Group(grName, depName);
            groups.push_back(n);
        }
    }
}

// создание студентов на основе данных из файла
void Deanery::hireStudents() {
    std::ifstream stData;
    stData.open("../data/id&fio.txt");

    std::string f;
    std::string i;
    std::string o;

    std::string fio;
    srand(time(0));
    if (stData.is_open()) {
        for (int j = 0; j < 40; ++j) {
            stData >> f;
            stData >> i;
            stData >> o;
            fio = f + " " + i + " " + o;
            Student *st = new Student(j++, fio);
            this -> groups[rand() % 3 + 1] -> addStudent(st);
        }
    }
}



// добавление случайных оценок студентам
void Deanery::addMarksToAll() {
    srand(time(0));
    for (auto &group : groups) {
        for (auto &st : group -> students) {
            for (int i = 0; i < 5; ++i) {
                std::default_random_engine generator;
                std::uniform_int_distribution<int> distribution(1, 5);
                st->addMark(distribution(generator));
            }
        }
    }
}

// получение статистики по успеваемости студентов и групп
void Deanery::getStatistics() {
    for (auto &group : groups) {
        std::cout << "Group " << group->title << " statistic : " << std::endl;
        int mark1 = 0;
        int mark2 = 0;
        int mark3 = 0;
        int mark4 = 0;
        int mark5 = 0;
        for (auto &student : group->students) {
            if (ceil(student->getAverageMark()) == 1) {
                mark1++;
            }
            if (ceil(student->getAverageMark()) == 2) {
                mark2++;
            }
            if (ceil(student->getAverageMark()) == 3) {
                mark3++;
            }
            if (ceil(student->getAverageMark()) == 4) {
                mark4++;
            }
            if (ceil(student->getAverageMark()) == 5) {
                mark5++;
            }
        }
        std::cout << "Average mark 5 amount of people: " << mark5 << std::endl;
        std::cout << "Average mark 4 amount of people: " << mark4 << std::endl;
        std::cout << "Average mark 3 amount of people: " << mark3 << std::endl;
        std::cout << "Average mark 2 amount of people: " << mark2 << std::endl;
        std::cout << "Average mark 1 amount of people: " << mark1 << std::endl;

        mark1 = 0;
        mark2 = 0;
        mark3 = 0;
        mark4 = 0;
        mark5 = 0;
    }
}

// перевод студентов из группы в группу
void Deanery::moveStudents(int id, std::string name) {
    for (auto &gr : groups) {
        if (gr->title == name) {
            for (auto grPre : groups) {
                for (auto st : grPre->students) {
                    if (st->id == id) {
                        gr->addStudent(st);
                        grPre->removeStudent(id);
                        std::cout << st->id << " transferred to " << st->group << std::endl;
                        break;
                    }
                }
            }
        }
    }


}

// отчисление студентов за неуспеваемость
void Deanery::fireStudents() {
    double togo = 3.0;
    for (auto &group : groups) {
        for (auto &student : group->students) {
            if (student->getAverageMark() < togo) {
                if (student->group != nullptr) {
                    student->group->removeStudent(student->id);
                }
            }
        }
    }
}

// сохранение обновленных данных в файлах
void Deanery::saveStuff() {
    std::ofstream out;
    out.open("../data/upd.txt");
    if (out.is_open()) {
        for (auto &gr : groups) {
            out << "department: " << gr->spec << "\n ";
            out << "group: " << gr->title << "\n";
            for (auto &st : gr->students) {
                out << "\t id: " << st->id << "\n \t fio: " << st->fio;
                if (st->isHeadOfGroup()) {
                    out << "\tgroup head\n";
                }
                out << "\taverage: " << st->getAverageMark() << "\n";
            }
            out << "\n";
        }
    }
}

// инициация выборов старост в группах
void Deanery::initHeads() {
    for (auto &group : groups) {
        group -> chooseHead();
    }
}

// вывод данных на консоль
void Deanery::output() {
    std::cout << std::endl;
    for (auto &group : groups) {
        std::cout << "\t" << "Title : " << group->title << std::endl;
        std::cout << "\t" << "Specification : " << group->spec << "\n";

        std::cout << std::endl;
        for (auto &student : group -> students) {
            std::cout << "ID : " << student->id << std::endl;
            std::cout << "Name :" << student->fio << std::endl;
            if (student->isHeadOfGroup()) {
                std::cout << "Head of the group" << std::endl;
            }
            std::cout << "Average : " << student->getAverageMark() << std::endl;
        }
    }
}

