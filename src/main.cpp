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
    std::cout << d.getStat();
    return 0;
}