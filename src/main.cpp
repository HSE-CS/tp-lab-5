// Copyright 2021 Lab_5 TiNa
#include "Student.h"
#include "Group.h"
#include "Deanary.h"
#include <iostream>

int main() {
    Deanery dec;
    // dec.createGroups();
    // dec.hireStudents();
    // dec.addMarksToAll();
    // dec.fireStudent();
    // dec.getStatistics();

    std::string fname1 = "Shherbakov Aleksey";
    Student stud1(21, fname1);
    stud1.addMark(6);
    std::string fname2 = "Osipova Anna";
    Student stud2(13, fname2);
    stud2.addMark(7);
    std::string title1 = "19pmi2";
    std::string spec1 = "PMI";
    Group gr1(title1, spec1);
    std::string title2 = "20pi1";
    std::string spec2 = "PI";
    Group gr2(title2, spec2);
    gr1.addStudent(&stud1);
    gr2.addStudent(&stud2);

    dec.moveStudents(stud1.getId(), gr1.getTitle(), gr2.getTitle());
    dec.moveStudents(stud2.getId(), gr2.getTitle(), gr1.getTitle());

    dec.getStatistics();

    // std::cout << gr2.getAveragemark_Gr();


    return 0;
}
