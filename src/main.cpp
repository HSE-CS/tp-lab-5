// Copyright [2020] <Olesya Nikolaeva>

#include "Deanary.h"

int main() {
    srand(0);
    std::ifstream file("groups_list.txt");
    Deanary newDea;
    newDea.createGroups(std::move(file));
    Student A("002", "Pavlov I. V.");
    A.addMark(10);
    A.addMark(10);
    newDea.addStudents(&A, "17FM");
    std::ifstream fileWithStudents("students_list_1.txt");
    std::ifstream fileWithStudents2("students_list_2.txt");
    newDea.readStudents(std::move(fileWithStudents));
    newDea.readStudents(std::move(fileWithStudents2));
    for (int i = 0; i < 5; i++)
        newDea.addMarksToAll();
    newDea.initHeads();
    newDea.saveStaff();
    Student B("1903", "Nikolaeva O. I.");
    B.addMark(10);
    B.addMark(9);
    newDea.addGroup(new Group("19SE", "Software Engineering"));
    B.groupIs(newDea.findGroup("19SE"));
    newDea.fireStudents(newDea.findStudent("Dochkin K. A."));
    newDea.getStatistic();
    return 0;
}
