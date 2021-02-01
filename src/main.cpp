// Copyright 2021 valvarl

#include <Deanery.h>


int main(int argc, char* argv[]) {
    // для генерации случайных чисел используется std::minstd_rand
    // со значением seed = 42
    Deanery deanery{};
    // поставим каждому студенту по три оценки во всех группах
    deanery.addMarksToAll(3);
    // напечатаем статистику
    deanery.getStatistics();
    // переместим двух самых способных студентов из числа самых слабых
    // в самую сильную группу
    std::string name = "Колесников Р.А";
    std::string title = "19FM-1";
    // переместим студента, зная его имя
    deanery.moveStudents(name, title);
    // переместим студента по id
    deanery.moveStudents(56, title);
    // отчислим старосту за неуспеваемость
    std::string name2 = "Яковлева У.";
    deanery.fireStudents(name2);
    // отчислим слабого студента по id
    deanery.fireStudents(72);
    // сохраним статистику в файле
    deanery.saveStuff();
    return 0;
}
