//
// Created by mila on 27.01.2021.
//

#ifndef TP_LAB_5_GROUP_H
#define TP_LAB_5_GROUP_H
//Разработать класс Group для хранения информации об учебной группе

#include <string>
#include <vector>

class Deanery;
class Student;

using namespace std;

class Group {
    friend class Deanery;
    friend class Student;
private:
    /* data */
//Примерный перечень полей:
    string title; // - название группы
    string spec; // - специальность
    vector <Student *> students; // - вектор ссылок на студентов
    Student *head; // - ссылка на старосту (из членов группы)


public:
    //Group (arguments);
    //virtual ~Group ();
//  Обеспечить класс следующими методами:

    //создание группы с указанием названия
    Group(string title, string spec) {
        this -> title = title;
        this -> spec = spec;
        this -> students = {};
        this -> head = nullptr;
    }


    //добавление студента
    void addStudent(Student *);

    //избрание старосты
    void chooseHead();

    //вычисление соеднего балла в группе
    double getAverageMark();

    //исключение студента из группы
    void removeStudent(const int&);

    Student *getStudent(const int&);

    bool isEmpty();


};

#endif //TP_LAB_5_GROUP_H
