// Copyright 2021 Igumnova Natasha
#include "Deanary.h"

#include <iostream>
#include <string>
#include <fstream>


int main() {
    Deanary D(3, "data.txt");
    D.getStatistic();
    //  D.moveStudents(210, "19_3");
    //  D.moveStudents(301, "19_2");
    //  D.addMarksToAll("19_1");
    //  D.getStatistic();
    //  D.saveStaff("data.txt");
    D.fireStudents(4.0);
    D.getStatistic();
}
