// Copyright 2020 S. BOR
#include "Deanary.h"
#include <iostream>

int main() {
    Student test(1, "Sergey Boryaev");
    test.getAvarageMark();
    Deanary testd;
    testd.createGroups();
    testd.createStudents();
    testd.saveStaff();
    Group gr("test", "test");
    std::cout << gr.isEmpty();
}
