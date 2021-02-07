// Copyright 2021 Kartseva Masha
#include <iostream>
#include <fstream>
#include"Deanary.h"
#include"Group.h"
#include"Student.h"


int main() {
    //system("chcp 65001");
    Deanary* fimicn = new Deanary();
    fimicn->addGroups("output.txt", "groups.txt");
    fimicn->chooseHeads();
    fimicn->set_random_marks(6);
    fimicn->getStatistics();
    std::cout << "=======================" << std::endl;
    fimicn->expelStudents();
    fimicn->getStatistics();
    std::cout << "=======================" << std::endl;
}
