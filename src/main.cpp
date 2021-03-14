// Copyright 2021 Grachev Alexander

#include <iostream>
#include "../include/Deanary.h"
#include "../include/Group.h"
#include "../include/Student.h"

int main() {
    // Student
    Student a(2312, "Grachev A.E.");

    std::cout << a.getId() << std::endl;
    a.setId(2112);
    std::cout << a.getId() << std::endl;

    std::cout << a.getName() << std::endl;
    a.setName("Grachev Alexander");
    std::cout << a.getName() << std::endl;

    a.addMark(10);
    a.addMark(9);
    a.addMark(5);
    a.addMark(8);
    std::cout << a.getMidMark() << std::endl;

    Student b(1111, "Ivanov I.I.");
    b.addMark(5);
    b.addMark(6);


    // Group
    Group gA("19PI", "PI");

    std::cout << gA.getTitle() << std::endl;
    std::cout << gA.getSpec() << std::endl;

    gA.addStudent(a);
    gA.addStudent(b);

    gA.chooseLeader(a);
    std::cout << gA.getLeader() << std::endl;

    std::cout << gA.getMidMark() << std::endl;

    std::cout << gA.searchStudent(1111).getName() << std::endl;
    std::cout << gA.searchStudent("Ivanov I.I.").getId() << std::endl;

    gA.removeStudent(2112);
    gA.removeStudent("Ivanov I.I.");

    return 0;
}
