// Copyright 2021 milalupehina

#ifndef TP_LAB_5_STUDENT_H
#define TP_LAB_5_STUDENT_H
// Разработать класс Student для хранения информации о студенте.
#include <string>
#include <vector>

#include "Group.h"

class Group;

using namespace std;
class Student {
    friend class Deanery;
    friend class Group;
 private:
    /* data */
// Примерный перечень полей:
    int id; // - идентификационный номер
    string fio; // - фамилия и инициалы
    Group *group; // - ссылка на группу (объект Group)
    vector <int> marks; // - вектор оценок

 public:
// Обеспечить класс следующими методами:
    // Student (arguments);
    // virtual Students ();

    // создание студента с указанием ИД и ФИО
    Student(int id, string fio) {
        this -> id = id;
        this -> fio = fio;
        this -> group = NULL;
        this -> marks = {};
    };

    // зачисление в группу
    void addToGroup(Group *);

    // добавление оценки
    void addMark(int);

    // вычисление средней оценки
    double getAverageMark();

    bool isHeadOfGroup();

};

#endif // TP_LAB_5_STUDENT_H
