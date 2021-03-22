// Copyright by JMax 2020

#include "Deanary.h"

int main() {
    Deanary deanary;
    deanary.createGroups(R"(../../src/groups.txt)");
    deanary.hireStudents(R"(../../src/students.txt)");
    deanary.addMarksToAll();
    deanary.initHeads();
    deanary.saveStaff(R"(../../src/statistics.txt)");

    deanary.moveStudent("Чижов Мирон Миронович", "19E-1", "19PI-2");

    deanary.getStatistics();

    deanary.fireStudents();

    deanary.saveStaff(R"(../../src/statistics1.txt)");

    return 0;
}
