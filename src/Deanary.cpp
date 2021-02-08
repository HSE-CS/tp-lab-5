//
// Created by toliman on 03.02.2021.
//

#include "../include/Deanary.h"


std::vector<Student *> Deanary::createStudents(int count) {
    std::vector<Student *> students(count);
    std::ifstream input("../../Students/students-list.txt");
//    system("pwd");
    int amount;
    std::string name;
    input >> amount;
//    std::cout << amount << '\n';
    for (int i = 0; i < std::min(amount, count); ++i) {
        input >> name;
//        std::cout << name << std::endl;
        students[i] = new Student(i, name);
    }
    input.close();
    return students;
}

