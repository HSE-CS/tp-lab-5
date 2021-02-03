// Copyright 2021 BekusovMikhail

#include <iostream>
#include "Deanary.h"
#include "Student.h"
#include "Group.h"

int main() {
    Deanary deanary;
    deanary.createGroups();
    deanary.sortStudents(deanary.hireStudents());
    deanary.initHeads();
    deanary.addMarksToAll();
    deanary.addMarksToAll();
    deanary.addMarksToAll();
//    deanary.getStatistics();
    std::vector<Student *> delstds = {new Student("00011", "Lester Mullins")};
    deanary.fireStudents(delstds);
    deanary.getStatistics();
    deanary.saveStaff();
    std::vector<Student *> movstds = {new Student("00000", "Allison Berry")};
    deanary.moveStudents(deanary.getGroups()[0],
            deanary.getGroups()[1], movstds);
    deanary.getStatistics();

    Group gr("PI", "software engineering");
    Student st ("00000", "William Garcia");
    gr.addStudent(&st);
    std::cout<<st.getGr()->getSpec();
}
