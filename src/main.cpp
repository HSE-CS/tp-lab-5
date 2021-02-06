// Copyright 2021 Egor Trukhin
#include <clocale>
#include <iostream>

#include "Deanary.h"

int main() {
  setlocale(LC_ALL, "Russian");
  srand(time(0));

  try {
    // Создание групп и студентов в них на основе двух файлов
    Deanary HSE("../src/groups.txt", "../src/students.txt");

    HSE.setRandomMarks(15);  // По 15 оценок каждому студенту
    HSE.setHeads();  // Лучший по среднему баллу студент в каждой группе

    // Общая информация по деканату
    std::cout << HSE.getInfo() << std::endl;
    // Deanary:
    //   Count of students: 114
    //   Count of groups: 4
    //   Groups:
    //     19PI-1 (29)
    //     19PI-2 (30)
    //     19PMI-1 (29)
    //     19PMI-2 (26)

    std::cout << "==================================================\n\n";

    // Подробная информация о каждой группе
    for (auto group : HSE.getGroups())
      std::cout << group->getInfo() << std::endl;

    std::cout << "==================================================\n\n";

    // Подробная информация о студентах-старостах:
    for (auto group : HSE.getGroups())
      std::cout << group->getHead()->getInfo() << std::endl;

    std::cout << "==================================================\n\n";

    // Отчислим всех студентов со средней оценкой < 6.0
    HSE.fireStudents(6.0);

    // Новая информация по деканату (цифры могут отличаться (рандом))
    std::cout << HSE.getInfo() << std::endl;
    // Deanary:
    //   Count of students: 14
    //   Count of groups: 4
    //   Groups:
    //       19PI-1 (3)
    //       19PI-2 (2)
    //       19PMI-1 (5)
    //       19PMI-2 (4)

    std::cout << "==================================================\n\n";

    // Переведм всех из 2ых групп в 1ые
    std::vector<Student*> move_list(HSE.getGroup("19PI-2")->getStudents());
    HSE.moveStudents(move_list, HSE.getGroup("19PI-1"));
    move_list = HSE.getGroup("19PMI-2")->getStudents();
    HSE.moveStudents(move_list, HSE.getGroup("19PMI-1"));

    // Подробная информация о каждой группе
    for (auto group : HSE.getGroups())
      std::cout << group->getInfo() << std::endl;

    // Новая информация по деканату (цифры могут отличаться (рандом))
    std::cout << HSE.getInfo() << std::endl;
    // Deanary:
    //   Count of students: 14
    //   Count of groups: 4
    //   Groups:
    //      19PI-1 (5)
    //      19PI-2 (0)
    //      19PMI-1 (9)
    //      19PMI-2 (0)

    std::cout << "==================================================\n\n";

    // Сохраним новые списки групп и студентов в новые файлы (можно и старые)
    HSE.saveData("../src/new_groups.txt", "../src/new_students.txt");

    // Прочитаем новые данные
    Deanary LOBACHEVSKY("../src/new_groups.txt", "../src/new_students.txt");

    // Информация по новому деканату
    std::cout << LOBACHEVSKY.getInfo() << std::endl;
  } catch (std::exception& error) {
    std::cerr << error.what() << std::endl;
  }
  return 0;
}
