//
// Created by mila on 27.01.2021.
//

#ifndef TP_LAB_5_GROUP_H
#define TP_LAB_5_GROUP_H
//Разработать класс Group для хранения информации об учебной группе

class Group {
private:
    /* data */
//Примерный перечень полей:
    char[100] title; // - название группы
    char[100] spec; // - специальность
    students - вектор ссылок на студентов
    head - ссылка на старосту (из членов группы)


public:
    //Group (arguments);
    //virtual ~Group ();
//  Обеспечить класс следующими методами:

    //создание группы с указанием названия


    //добавление студента
    addStudent();
    //избрание старосты
    chooseHead();
    //поиск студента по ФИО или ИД
    containsStudent();
    //вычисление соеднего балла в группе
    getAverageMark();
    //исключение студента из группы
    removeStudent();

    getStudent();
    isEmpty();


};

#endif //TP_LAB_5_GROUP_H
