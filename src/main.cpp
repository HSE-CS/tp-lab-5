// Copyright 2021 Bekina Svetlana
#include "Deanary.h"
#include "Group.h"
#include "Student.h"
//#include "Windows.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Deanary groups;
    groups.createGroup();
    groups.hireStudents();
    groups.addMarksToAll();
    groups.initHeads();
    groups.getStatistics();
    groups.fireStudents();
    groups.getStatistics();
    return 0;
}
