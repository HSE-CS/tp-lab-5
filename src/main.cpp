// Copyright 2021 Tyulin Igor

#include <string>
#include <fstream>

#include "Deanary.h"
#include "Group.h"
#include "Student.h"

int main() {
    Student student_1(9, "Michail Volkov");
    std::cout << student_1.stud_fio() << std::endl;
    std::cout << student_1.stud_id() << std::endl;
    Group se("19pi-1", "software engineering");
    std::cout << "Title: " << se.getitle() << " Spec: " << se.getspec() << std::endl;
    student_1.group_add(&se);
    student_1.mark_add(9);
    student_1.mark_add(9);
    student_1.mark_add(4);
    student_1.mark_add(7);
    student_1.mark_add(4);
    student_1.mark_add(1);
    std::cout << student_1.average_mark() << std::endl;
    Deanary club;
    club.createGroups(se);
    club.hireStudents(&student_1,"software engineering");
    Student student_2(2, "Ya Zdes");
    student_2.group_add(&se);
    student_2.mark_add(1);
    student_2.mark_add(2);
    student_2.mark_add(1);
    club.hireStudents(&student_2,"software engineering");
    club.getStatistics();
    student_1.mark_add(6);
    student_2.mark_add(6);
    se.addstud(&student_1);
    se.addstud(&student_2);
    std::cout << se.studavermarks() << std::endl;
    se.sethead(&student_1);
    std::cout << se.gethead();
    return 0;
}