// Copyright 2021 dmitrycvetkov2000

#include "Student.h"
#include "Group.h"
#include "Deanary.h"

#include <string>
#include <fstream>

int main() {
    Deanary deanary;

    const std::string groupsFilePath("./groups.txt");
    std::ifstream groupsStream(groupsFilePath, std::ios::in);
    deanary.createGroups(groupsStream);
    groupsStream.close();

    const std::string studentsFilePath("./students.txt");
    std::ifstream studentsStream(studentsFilePath, std::ios::in);
    deanary.hireStudents(studentsStream);
    studentsStream.close();

    deanary.initHeads();

    for (int i = 0; i < 20; ++i) {
        deanary.addMarksToAll();
    }

    deanary.getStatistics();

    const std::string outputFilePath("./out.txt");
    std::ofstream outputStream(outputFilePath, std::ios::out);
    deanary.saveStaff(outputStream);
    outputStream.close();

    return 0;
}
