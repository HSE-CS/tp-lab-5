//Copyright 2020 Uskova
#include <iostream>
#include <fstream>
#include "Deanary.h"
#include "Group.h"
#include "Student.h"


int main() {
    Deanary* deanary = new Deanary;
    std::vector<Student*> sts = deanary->hireStudents("students.txt");
    deanary->createGroups("spec.txt", sts);
    deanary->addMarks(6);
    deanary->initHeads();
    deanary->showData();
    deanary->fireStudents();
    std::cout << std::endl << "After firing:" << std::endl << std::endl;
    deanary->showData();
    deanary->moveStudents(deanary->findId(5),
                          deanary->findGr("1", "Economics"));
    std::cout << std::endl << "After moving 5:" << std::endl << std::endl;
    deanary->showData();
    deanary->getStatistic("statistics.txt");
    deanary->saveChangesInFile("data.txt");
    return 0;
}