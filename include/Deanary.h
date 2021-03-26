// Copyright 2021 milalupehina

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <ctime>

#include "Student.h"
#include "Group.h"

// using namespace std;

// Разработать класс Deanery
class Deanery {
    friend class Student;
    friend class Group;
 private:
    // groups - массив групп
    std::vector <Group *> groups;

 public:
    // Обеспечить класс следующими методами:

    // создание студентов на основе данных из файла
    void hireStudents();
    // создание групп на основе данных из файла
    void createGroups();
    // добавление случайных оценок студентам
    void addMarksToAll();
    // получение статистики по успеваемости студентов и групп
    void getStatistics();
    // перевод студентов из группы в группу
    void moveStudents(int, std::string);
    // отчисление студентов за неуспеваемость
    void fireStudents();
    // сохранение обновленных данных в файлах
    void saveStuff();
    // инициация выборов старост в группах
    void initHeads();

    // вывод данных на консоль
    void output();
};

#endif  //  INCLUDE_DEANARY_H_
