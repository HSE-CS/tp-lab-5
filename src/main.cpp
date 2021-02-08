// Copyright 2021 Shatilov Victor

#include "Deanary.h"
#include <iostream>

using namespace std;

int main() {
    Deanary d;
    d.createGroupsFromFile("groups.txt");
    d.createStudentsFromFile("students.txt");
    d.addRandomMarks();
    d.initHeads();
    cout << d.getStatistics() << endl;
    d.saveToFile("results.txt");

    return 0;
}