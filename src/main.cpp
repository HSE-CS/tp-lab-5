// Copyright Roman Balayan @ 2021

#include <iostream>

#include "Creator.h"
#include "Deanary.h"

int main() {
    std::cout << "Hello" << std::endl;
    Creator creator;
    std::unique_ptr<Deanary> deanary = creator.fabricMethod();

    deanary->printStatistics();
    deanary->addRandomMarks();
    std::cout << "new marks:\n";
    deanary->printStatistics();

    return 0;
}
