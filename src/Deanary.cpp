// Copyright 2021 milalupehina
#include <iostream>
#include <fstream>

#include "Deanary.h"

// Разработать класс Deanery
/*
class Deanery {
 private:
    */
/* data */
/*

// Примерный перечень полей:

    groups - массив групп

 public:
    // Deanery (arguments);
    // virtual ~Deanery ();
    // Обеспечить класс следующими методами:
*/



//создание студентов на основе данных из файла
void Deanery::hireStudents() {


};

//создание групп на основе данных из файла
void Deanery::createGroups() {

};

//добавление случайных оценок студентам
void Deanery::addMarksToAll() {

};

//получение статистики по успеваемости студентов и групп
void Deanery::getStatistics() {
    int n = 0;
    for (auto &group : groups) {
        cout << "Group " << n << " statistic : " << endl;
        int mark1 = 0;
        int mark2 = 0;
        int mark3 = 0;
        int mark4 = 0;
        int mark5 = 0;
        for (auto &student : group->students) {
            if (student->getAverageMark() == 1) {
                mark1++;
            }
            if (student->getAverageMark() == 2) {
                mark2++;
            }
            if (student->getAverageMark() == 3) {
                mark3++;
            }
            if (student->getAverageMark() == 4) {
                mark4++;
            }
            if (student->getAverageMark() == 5) {
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

//перевод студентов из группы в группу
void Deanery::moveStudents() {

};

//отчисление студентов за неуспеваемость
void Deanery::fireStudents() {

};

//сохранение обновленных данных в файлах
void Deanery::saveStuff() {

};

//инициация выборов старост в группах
void Deanery::initHeads() {
    for (auto &group : groups) {
        group -> chooseHead();
    }
};

//вывод данных на консоль
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

//};