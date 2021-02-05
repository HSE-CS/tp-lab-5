// Copyright 2020 Osmanov Islam
#include <iostream>
#include <string>
#include "Reader.h"
#include "Deanary.h"
#include "Student.h"

int main() {
    Deanary dec = Deanary();
    dec.createGroups("Students.txt", "Groups.txt");
    dec.initHeads();
    std::cout << "------" << std::endl;
    dec.printGroupsHeads();
    std::cout << "------" << std::endl;
    dec.addMarksToAll();
    dec.fireStudents();
    dec.getStatistics();
    dec.saveStuff("DeanFile.txt");
    return 0;
}
