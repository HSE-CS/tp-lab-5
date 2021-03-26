// Copyright [2021] <Nikita Semaev>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "../include/Deanery.h"

void test(std::string &&str) {}

int main() {
    std::srand(std::time(nullptr));
    Deanery deanery({"test.txt"});
    for (std::size_t i = 0; i < 4; ++i) {
        deanery.randomMarks();
    }
    std::cout << deanery;

    std::cout << "\n!end!\n";
    return 0;
}
