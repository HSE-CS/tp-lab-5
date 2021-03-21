// Copyright Mushka Nikita, 2021

#include <iostream>
#include "../include/Deanary.h"

int main() {
    Student s = Student(1, "a s");
    Student *s1 = &s;

    Group g = Group("PI", "programming");
    Group *g1 = &g;
    g.ChooseLeader(s1);
    std::cout << g.GetLeader()->GetFio() << '\n';

    Deanary d;
    d.File_CreateGroups("data_groups.txt");
    d.File_CreateStudents("data_students.txt");
    d.FillMarks();
    d.ChooseLeaders();
    std::cout << d.GetStats();
    d.File_SaveDeanary("save_file.txt");
}
