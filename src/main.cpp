// Copyright Mushka Nikita, 2021

#include <iostream>
#include "../include/Deanary.h"

int main() {
    Deanary d;
    d.File_CreateGroups("C:/Users/mushka/Desktop/tp-lab-5/src/data_groups.txt");
    d.File_CreateStudents(
            "C:/Users/mushka/Desktop/tp-lab-5/src/data_students.txt");
    d.FillMarks();
    d.ChooseLeaders();
    std::cout << d.GetStats();
    d.File_SaveDeanary("C:/Users/mushka/Desktop/tp-lab-5/src/save_file.txt");
}
