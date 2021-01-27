//
// Created by mila on 27.01.2021.
//

#ifndef TP_LAB_5_STUDENT_H
#define TP_LAB_5_STUDENT_H
//Разработать класс Student для хранения информации о студенте.
class Student {
private:
    /* data */
//Примерный перечень полей:
    int id; // - идентификационный номер
    char[100] fio; // - фамилия и инициалы
    group - ссылка на группу (объект Group)
    marks - вектор оценок

public:
//Обеспечить класс следующими методами:
    //Student (arguments);
    //virtual Students ();

    //создание студента с указанием ИД и ФИО

    //зачисление в группу
    addToGroup();
    //добавление оценки
    addMark();
    //вычисление средней оценки
    getAverageMark();

    isHeadOfGroup();
ToGroup();
//добавление оценки
addMark();
//вычисление средней оценки
getAverageMark();

isHeadOfGroup();
};

#endif //TP_LAB_5_STUDENT_H
