// Copyright 2021 milalupehina


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <ctime>

#include "Deanary.h"

int main() {
    Deanery fe;
    fe.createGroups();
    fe.hireStudents();
    fe.initHeads();

    fe.addMarksToAll();
    fe.getStatistics();


    fe.moveStudents(24, "groupSuits");
    fe.fireStudents();
    fe.saveStuff();



}
