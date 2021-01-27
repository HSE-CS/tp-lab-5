//
// Created by mila on 27.01.2021.
//

#ifndef TP_LAB_5_DEANARY_H
#define TP_LAB_5_DEANARY_H
//Разработать класс Deanery
class Deanery {
private:
    /* data */
//Примерный перечень полей:

    //groups - массив групп

public:
    //Deanery (arguments);
    //virtual ~Deanery ();
    //Обеспечить класс следующими методами:

    //создание студентов на основе данных из файла
    hireStudents();
    //создание групп на основе данных из файла
    createGroups();
    //добавление случайных оценок студентам
    addMarksToAll();
    //получение статистики по успеваемости студентов и групп
    getStatistics();
    //перевод студентов из группы в группу
    moveStudents();
    //отчисление студентов за неуспеваемость
    fireStudents();
    //сохранение обновленных данных в файлах
    saveStuff();
    //инициация выборов старост в группах
    initHeads();
    //вывод данных на консоль
    output();

};

#endif //TP_LAB_5_DEANARY_H
