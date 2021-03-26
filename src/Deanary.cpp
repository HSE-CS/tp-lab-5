// Copyright 2021 milalupehina
#include <iostream>
#include <fstream>

#include "Deanary.h"

// Разработать класс Deanery

// создание групп на основе данных из файла
void Deanery::createGroups() {
    ifstream grData;
    grData.open("../data/departments.txt");

    string grName;
    string depName;

    if (grData.is_open()) {
        for (int i = 0; i < 4; ++i) {
            grData >> grName;
            grData >> depName;
            Group *n = new Group(grName,depName);
            groups.push_back(n);
        }
    }

};

// создание студентов на основе данных из файла
void Deanery::hireStudents() {
    ifstream stData;
    stData.open("../data/id&fio.txt");

    string f;
    string i;
    string o;

    string fio;
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
};



// добавление случайных оценок студентам
void Deanery::addMarksToAll() {
    srand(time(0));
    for (auto &group : groups) {
        for (auto &st : group -> students) {
            for (int i = 0; i < 5; ++i) {
                st -> addMark(rand() % 5 + 0);
            }
        }
    }
};

// получение статистики по успеваемости студентов и групп
void Deanery::getStatistics() {
    for (auto &group : groups) {
        cout << "Group " << group->title << " statistic : " << endl;
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
        cout << "Average mark 5 amount of people: " << mark5 << endl;
        cout << "Average mark 4 amount of people: " << mark4 << endl;
        cout << "Average mark 3 amount of people: " << mark3 << endl;
        cout << "Average mark 2 amount of people: " << mark2 << endl;
        cout << "Average mark 1 amount of people: " << mark1 << endl;

        mark1 = 0;
        mark2 = 0;
        mark3 = 0;
        mark4 = 0;
        mark5 = 0;

    }
};

// перевод студентов из группы в группу
void Deanery::moveStudents() {

};

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

};

// сохранение обновленных данных в файлах
void Deanery::saveStuff() {
    ofstream out;
    out.open("../data/upd.txt");
    if (out.is_open()) {
        for (auto &gr : groups) {
            out << "department: " << gr->spec << "\n group: " << gr->title << "\n";
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

};

// инициация выборов старост в группах
void Deanery::initHeads() {
    for (auto &group : groups) {
        group -> chooseHead();
    }
};

// вывод данных на консоль
void Deanery::output() {
    cout << endl;
    for(auto &group : groups) {
        cout << "\t" << "Title : " << group->title << endl;
        cout << "\t" << "Specification : " << group->spec << endl << endl;

        cout << endl;
        for (auto &student : group -> students) {
            cout << "ID : " << student->id << endl;
            cout << "Name :" << student->fio << endl;
            if (student->isHeadOfGroup()) {
                cout << "Head of the group" << endl;
            }
            cout << "Average : " << student->getAverageMark() << endl;
        }
    }

};

