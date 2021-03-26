// Copyright 2021 PaninaPolina
#include "Deanary.h"
#include "Group.h"
#include "Student.h"

int main() {

    Deanery deanery("Students.txt", "Group.txt");
    deanery.CreateStudents();
    deanery.CreateGroups();
    deanery.addMarks();
    deanery.electGhead();

    deanery.exceptionStudent();
    deanery.changeGroup("Teterina Alexandra Artemovna", "PMI-3");
    deanery.changeGroup("Yakushev Pavel Danilovich", "PMI-1");
    deanery.changeGroup("Klimov Egor Alekseevich", "PMI-2");

    deanery.getStatistics("Statistics.txt");
    deanery.update("Data.txt");
    deanery.printinfo();
  }
