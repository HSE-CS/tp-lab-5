// Copyright 2021 soda

#include "Deanary.h"

int main() {
    Deanary HSE{};
    // Add two marks to all students
    HSE.addMarksToAll(2);
    std::string str = "Business Informatics";
    // Move student with id - 1 in BI Group;
    HSE.moveStudents(1, str);
    // Fire srudent with id - 4.
    HSE.fireStudents(4);
    // Move student with fio
    std::string stu = "Jacobs John Oliver";
    HSE.moveStudents(stu, str);
    // Print stat
    HSE.printStat();
    // Fire all weak students
    HSE.fireWeakStudents();
    // Save stat in file statistic
    HSE.saveStuff();
    return 0;
}
