// Copyright 2021 Sozinov Kirill
#include <Deanary.h>
#include <locale>
#include <iostream>
#include <fstream>
#include <vector>

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Deanery deanery{};
    std::cout << std::endl;
    deanery.moveStudents(std::vector<Student *>
    {deanery.getGroup(0)->getStudent("Pedro Smith")},
        deanery.getGroup(1));
    deanery.printGroups();
    deanery.addMarksToAll();
    deanery.printStatistics();
    deanery.fireStudents(3.);
    deanery.printGroups();
    deanery.saveStaff();
    deanery.printHeads();
    return 0;
}
