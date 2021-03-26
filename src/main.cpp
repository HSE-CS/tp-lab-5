// Copyright 2021 PaninaPolina
#include "Deanary.h"
#include "Group.h"
#include "Student.h"
using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");

    Deanery deanery("Students.txt", "Group.txt");
    deanery.CreateStudents();
    deanery.CreateGroups();
    deanery.addMarks();
    deanery.electGhead();

    deanery.exceptionStudent();
    deanery.changeGroup("Тетерина Александра Артемовнаа", "ПМИ-3");
    deanery.changeGroup("Якушев Тимур Тимофеевич", "ПМИ-1");
    deanery.changeGroup("Прохоров Артем Константинович", "ПМИ-2");

    deanery.getStatistics("Statistics.txt");
    deanery.update("Data.txt");
    deanery.printinfo();
  }
