// Copyright 2020 Longa Bonga
#include <cstring>
#include <iostream>
#include <string>
#include "Deanery.h"

int main() {
  // Student check
  // Student student("Ivan Dobryaev");
  // std::cout << student.getAveragemark() << '\n';
  // std::cout << student.isHeadOfGroup() << '\n';

  // Group check
  // Student student1("Ivan Dobryaev");
  // student1.addmark(10);
  // student1.addmark(9);

  // Student student2("Vladimir Putin");
  //
  // student1.addmark(3);
  // student1.addmark(5);

  // Group pmi("19-2", "pmi");
  // std::cout << pmi.isEmpty() << '\n';
  //
  // pmi.addStudent(& student1);
  // pmi.addStudent(& student1);
  // std::cout << pmi.isEmpty() << '\n';
  //
  // std::cout << pmi.getAveragemark() << '\n';
  //
  // pmi.chooseHead();
  //
  // std::cout << student1.isHeadOfGroup() << '\n';
  //
  // pmi.removeStudent(-1);
  //
  // std::cout << pmi.isEmpty() << '\n';

  Deanery deanery{};
    // поставим каждому студенту по три оценки во всех группах
    deanery.addMarksToAll(3);
    // напечатаем статистику
    deanery.getStatistics();
}
