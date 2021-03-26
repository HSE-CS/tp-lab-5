// Copyright 2021 by Liza

#include "Deanary.h"

int main() {
std::ifstream file("groups.txt");
Deanary newDea;
newDea.createGroups(std::move(file));
Student A("000", "Ivanov I. I.");
A.addmark(10);
A.addmark(10);
newDea.addStudents(&A, "20AMCS");
Student B("1111", "Ivanova I. I.");
B.addmark(10);
B.addmark(10);
newDea.addStudents(&A, "20AMCS");
newDea.addGroup(new Group("17IS", "Information Security"));
B.getGroup(newDea.findGroup("17IS"));
std::ifstream filewStudents("spisok.stud.1.txt");
std::ifstream filewStudents2("spisok.stud.2.txt");
newDea.hireStudents(std::move(filewStudents));
newDea.hireStudents(std::move(filewStudents2));
for (int i = 0; i < 5; i++)
newDea.addMarksToAll();
newDea.initHeads();
newDea.saveStaff();
newDea.fireStudents(newDea.findStudent("Kuznetsov I. B."));
newDea.getStatistics();
return 0;}
