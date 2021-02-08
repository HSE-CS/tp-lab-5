// Copyright 2021 Shatilov Victor

#include "Deanary.h"
#include <iostream>

int main() {
    Deanary d;
    d.createGroupsFromFile("groups.txt");
    d.createStudentsFromFile("students.txt");
    d.addRandomMarks();
    d.initHeads();
    std::cout << d.getStatistics() << std::endl;
    d.saveToFile("results.txt");

    return 0;
}
