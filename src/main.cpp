// Copyright 2021 by Sid

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include "Student.hpp"
#include "Group.hpp"
#include "Deanary.h"

void printVec(std::vector<std::string> arr) {
    for (auto str : arr) {
        std::cout << str << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    srand(int(time(NULL)));
    Deanery d("database.txt", "groups.txt");
    d.add_marks_for_groups();
    d.data_output();
// d.head_choices();
    d.calculate_means();
    d.expell_students();
    std::cout << "=============================" << std::endl << std::endl;
    d.data_output();
    d.save_data("output.txt");
}
