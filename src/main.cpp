// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 06.02.2021.
//
#include <iostream>
#include "Deanary.h"
#include "Student.h"
#include "Group.h"

int main() {
    Deanary d;
    d.readFile("Dataset.txt");
    d.addMarks();
    d.addMarks();
    d.addMarks();
    d.transferStudent(2, 3);
    d.transferStudent(22, 4);
    d.transferStudent(60, 1);
    d.saveStaff("Dataset.txt");
    Group *g2 = d.createGroup("english language", 90);
    d.hireStudent(302, "Шафин fy tt", "english language", 90);
    std::cout << g2->containsStudent(302);
    std::cout << d.getStat();
    return 0;
}
