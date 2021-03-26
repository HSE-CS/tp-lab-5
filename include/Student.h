// Copyright 2021 milalupehina

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
// Разработать класс Student для хранения информации о студенте.
#include <string>
#include <vector>

#include "Group.h"

class Group;

// using namespace std;
class Student {
    friend class Deanery;
    friend class Group;
 private:
// Примерный перечень полей:
    int id;  //  идентификационный номер
    std::string fio;  //  фамилия и инициалы
    Group *group;  //  ссылка на группу (объект Group)
    std::vector <int> marks;  //  вектор оценок

 public:
// Обеспечить класс следующими методами:

    // создание студента с указанием ИД и ФИО
    Student(int id, std::string fio) {
        this -> id = id;
        this -> fio = fio;
        this -> group = NULL;
        this -> marks = {};
    }

    // зачисление в группу
    void addToGroup(Group *);

    // добавление оценки
    void addMark(int);

    // вычисление средней оценки
    double getAverageMark();

    bool isHeadOfGroup();
};

#endif  // INCLUDE_STUDENT_H_
