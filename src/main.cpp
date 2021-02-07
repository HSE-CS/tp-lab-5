// Copyright 2021 Stifeev Nikita

#include "Deanary.h"

int main(int argc, char* argv[])
{
    std::string fileGroups = "groups.txt";
    std::string fileStudents = "students.txt";
    Deanary dean;
    dean.createGroups(fileGroups);
    dean.createStudents(fileStudents);
    dean.addMarksToAll();
    std::vector<double> res = dean.getStatistics();
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    dean.save("res.txt");
    return 0;
}
