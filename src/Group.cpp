//
// Created by mila on 27.01.2021.
//

#include "Group.h"

/*

//Разработать класс Group для хранения информации об учебной группе
class Group {
private:
    */
/* data *//*

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


*/
    //добавление студента
    void Group::addStudent(Student *neW) {
        students.push_back(neW);
    };

    //избрание старосты
    void Group::chooseHead() {
        if (students.size() == 0) return;
        int num = rand() % students.size() + 0;
        this -> head = students[num];
    };

    //вычисление соеднего балла в группе
    double Group::getAverageMark() {
        double rez = 0;
        int n = students.size();
        for (int i = 0; i < n; ++i) {
            rez += students[i] -> getAverageMark();
        }
        if (n == 0) { return 0; } else { return rez/n; };
    };

    //исключение студента из группы
    void Group::removeStudent(const int &id) {

    };

    Student *Group::getStudent(const int &id) {
        for (auto &student : students) {
            if ( student->id == id ) {
                return student;
            }
        }
    };

    bool Group::isEmpty() {
        return students.empty();
    };

/*

};

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
*/
