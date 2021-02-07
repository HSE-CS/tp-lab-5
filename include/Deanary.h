//
// Created by mila on 27.01.2021.
//

#ifndef TP_LAB_5_DEANARY_H
#define TP_LAB_5_DEANARY_H

#include <vector>
#include <string>

#include "Student.h"
#include "Group.h"

using namespace std;

//Разработать класс Deanery
class Deanery {
    friend class Student;
    friend class Group;
private:
    /* data */
//Примерный перечень полей:

    //groups - массив групп
    vector <Group *> groups = {};

public:
    //Deanery (arguments);
    //virtual ~Deanery ();

    //Обеспечить класс следующими методами:

    //Deanery();

    //создание студентов на основе данных из файла
    void hireStudents();
    //создание групп на основе данных из файла
    void createGroups();
    //добавление случайных оценок студентам
    void addMarksToAll();
    //получение статистики по успеваемости студентов и групп
    void getStatistics();
    //перевод студентов из группы в группу
    void moveStudents();
    //отчисление студентов за неуспеваемость
    void fireStudents();
    //сохранение обновленных данных в файлах
    void saveStuff();
    //инициация выборов старост в группах
    void initHeads();

    //вывод данных на консоль
    void output();

};

#endif //TP_LAB_5_DEANARY_H
