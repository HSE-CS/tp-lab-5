// Copyright Roman Balayan @ 2021

#include <iostream>

#include "../include/Creator.h"

int main() {
    std::cout << "Hello" << std::endl;
    Creator creator;
    auto deanary = creator.fabricMethod("./data.txt");

    deanary->printStatistics();
    deanary->addRandomMarks();
    std::cout << "new marks:\n";
    deanary->printStatistics();

    return 0;
}
